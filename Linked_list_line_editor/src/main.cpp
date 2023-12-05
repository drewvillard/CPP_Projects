#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/linked_list.h"
#include <cstring>

using namespace std;
/**
 * Main function for a simple text editor program using a linked list.
 *
 * This program allows the user to interactively manipulate a linked list of text entries,
 * providing commands for inserting, deleting, and displaying text entries, and saving
 * the content to a file.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line arguments, where argv[1] should be the name of the file to read and write.
 * @return An integer exit code, where 0 indicates successful execution and non-zero values indicate errors.
 */
int main(int argc, char **argv) {
    LinkedList list;
    string user_input;
    std::stringstream ss;
    char command;
    list.moveCursorTo(0);
    int current_position = 0;
    bool prog_engine = false;
    int id = 1;

    if (argc != 2) {
        cout << "In order to user the program enter " << argv[0] << " <FILE_NAME>.txt";
        return 1;
    }
    //sets constant FILE_NAME using user entry from command line arguments
    const char *FILE_NAME = argv[1];
    std::ifstream file_in(FILE_NAME);

    if (file_in.is_open()) {
        std::string line;
        int id = 1;

        //Fill the list with file data
        while (std::getline(file_in, line)) {
            char *cstr_line = new char[line.length() + 1];
            strcpy(cstr_line, line.c_str());
            list.add(id, cstr_line);
            id++;
            current_position++;
        }
        list.moveCursorToEnd();
        cout << list;
    } else {
        //if no file was found create one and return an error if it doesnt work
        std::ofstream new_file(FILE_NAME);
        if (!new_file.is_open()) {
            std::cerr << "Error: Unable to create file '" << FILE_NAME << "'." << std::endl;
            return 1;
        } else {
        }
    }

    while (!prog_engine) {
        string to_insert;

        //if-else for proper display upon inital execution
        if (list.isEmpty()) {
            cout << "1>";
        } else {
            cout << (list.getCursorPosition() + 1) << ">";
        }

        //user input gathering
        std::getline(cin, user_input);
        ss.clear();
        ss.str(user_input);
        char first_char = ' ';

        /*Validation (if user enters a word that may represent a false positive of one of the commands (IDLE) then check
        * the next character and if its a space or null terminator then its a valid command ( with some more extensive
        * validation for I as it is a common word)*/
        if (ss >> first_char &&
            (first_char == 'e' || first_char == 'E' || first_char == 'l' || first_char == 'L' || first_char == 'd' ||
             first_char == 'D' || first_char == 'i' || first_char == 'I')) {
            // Check if the next character is a space or if there's nothing after it
            char next_char = '\0';
            ss.get(next_char);

            if ((next_char == ' ' || next_char == '\0')) {
                char third_char;

                if ((first_char == 'i' || first_char == 'I') && (ss.get(third_char)) && (!isalpha(third_char))) {
                    command = first_char;
                } else if ((first_char == 'i' || first_char == 'I' && next_char == ' ') &&
                           (!ss.get(third_char) || !isalpha(static_cast<unsigned char>(third_char)))) {
                    // Valid command
                    command = first_char;
                } else {

                    if (first_char == 'e' || first_char == 'E' || first_char == 'l' || first_char == 'L' ||
                        first_char == 'd' ||
                        first_char == 'D') {
                        command = first_char;
                    }
                }
            }

        } else {
            //if the character is not one of the commands it will just be added to the list (desired effect)
            command = first_char;
        }

        //Handling the insert command
        if (command == 'I' || command == 'i') {
            //reset the stringstream
            ss.str(user_input);
            ss >> command;
            int start_id = -1;

            if (ss >> start_id) {}
            char second_command = 'z';

            //if id entered then make it our position and if not use current pos
            if (start_id > -1) {
                current_position = start_id;
            } else {
                current_position = list.getCursorPosition() + 1;
            }

            //inner while loop to handle user entering another command within the insert loop
            while (second_command != 'e' && second_command != 'E' && second_command != 'l' &&
                   second_command != 'L' && second_command != 'd' && second_command != 'D') {
                char next_char;
                cout << current_position << ">";
                std::getline(cin, to_insert);
                ss.clear();
                ss.str(to_insert);
                ss >> second_command;

                /*if this second command is one of the non insert commands look at the next character
                 *and if its a space, null term, or end of file we assume its a proper command
                 * otherwise we leave the second command blank to continue gathering node data to insert*/
                if (second_command == 'e' || second_command == 'E' || second_command == 'l' ||
                    second_command == 'L' || second_command == 'd' || second_command == 'D') {

                    if (ss.peek() == ' ' || ss.peek() == '\0' || ss.peek() == EOF) {
                        command = second_command;
                        break;
                    }
                    second_command = ' ';
                }

                //if there is an entered id then we use the insert command and if not we add to end of list
                if (start_id > -1) {
                    list.insert(const_cast<char *>(to_insert.c_str()), start_id);
                    // Increment current position
                    start_id++;
                    current_position++;
                } else {
                    list.add(current_position, const_cast<char *>(to_insert.c_str()));
                    current_position++;
                }
            }
        }
        //exit command writes to file all list content
        if (command == 'e' || command == 'E') {
            list.writeToFile(FILE_NAME);
            //turns off while loop running user input
            prog_engine = true;
            break;
        }

        //Delete command uses remove function
        if (command == 'd' || command == 'D') {
            int start_id = -1, end_id = -1;

            if (ss >> start_id && ss >> end_id) {
                list.remove(start_id, end_id);
                list.moveCursorTo(end_id);
            } else {
                list.remove(start_id, start_id);
                list.moveCursorTo(start_id);
            }
            /*else-if uses overloaded operator, and .printRange function to produce either
             * a range, one node, or the list*/
        } else if (command == 'l' || command == 'L') {
            int start_id = -1, end_id = -1;

            if (ss >> start_id) {
                if (ss >> end_id) {
                    list.printRange(start_id, end_id);
                    list.moveCursorTo(end_id);
                }
                if (end_id < 0) {
                    list.printRange(start_id, start_id);
                    list.moveCursorTo(start_id);
                }
            } else {
                cout << list;
                list.moveCursorToEnd();
            }
            //if the command is none of our expected ones(IDLE) add the entry to the list at either
            //the begining, end ,or current position.
        } else {
            if (list.isEmpty()) {
                list.add(1, const_cast<char *>(user_input.c_str()));
            } else {
                int lastPosition = list.getSize();

                if (list.getCursorPosition() == lastPosition) {
                    //insure cursor is at the end using created function
                    list.moveCursorToEnd();
                    //add just past our cursor
                    list.add(list.getCursorPosition() + 1, const_cast<char *>(user_input.c_str()));
                } else {
                    list.add((list.getCursorPosition()), const_cast<char *>(user_input.c_str()));
                }
            }
        }
    }
    return 0;
}