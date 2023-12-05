//
// Created by drew on 2023-11-17.
//

#include "spell_checker.h"

spell_checker::spell_checker(std::string test_name, std::string output_file,std::string dictionary_file) {
    m_dictionary_file=dictionary_file;
    fill_BST();
    BST_to_file(output_file);
    load_test(test_name);
    std::vector<std::string> words;
    words = spell_check();
    int size = words.size();

    //output misspelled words for main method
    std::cout << "Misspelled Words: " << size << std::endl;
    for (const auto &word: words) {
        std::cout << word << " " << std::endl;
    }
}

// Function to fill binary search tree (BST) with words from the dictionary file
void spell_checker::fill_BST() {
    try {
        // Open the dictionary file
        std::ifstream dictionary_file(m_dictionary_file);

        if (!dictionary_file.is_open()) {
            throw std::runtime_error("Error opening the dictionary file.");
        }

        std::string word;
        while (dictionary_file >> word) {
            m_bst.insert(word);
        }
        dictionary_file.close();

        //UX updates
        std::cout << "Binary Search Tree Filled." << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void spell_checker::BST_to_file(std::string file_name) {
    try {
        std::ofstream openfile(file_name);
        if (!openfile.is_open()) {
            throw std::runtime_error("Error opening the file.");
        }
        openfile << m_bst;
        openfile.close();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

// Function to load words from a test file and convert them to lowercase
int spell_checker::load_test(std::string file_name) {
    try {
        std::ifstream file(file_name);
        if (!file.is_open()) {
            throw std::runtime_error("Error opening the file.");
        }

        // Vector to store parsed words
        std::vector<std::string> words;
        std::string line;

        // Read the entire line from the file
        std::getline(file, line);

        // Use a regex to split the line into words (excluding numbers and special characters)
        std::regex wordRegex(R"(\b[a-zA-Z]+\b)");
        auto words_begin = std::sregex_iterator(line.begin(), line.end(), wordRegex);
        auto words_end = std::sregex_iterator();

        // Iterate through regex matches and add trimmed lowercase words to the vector
        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            //dereference iterator store in match then store in string
            std::smatch match = *i;
            std::string word = match.str();

            // Find the position of the first character that is not a whitespace or tab in the word
            size_t start = word.find_first_not_of(" \t\n\r");

            // Find the position of the last character that is not a whitespace or tab in the word
            size_t end = word.find_last_not_of(" \t\n\r");

            // Check if both start and end positions are valid
            if (start != std::string::npos && end != std::string::npos) {
                // Extract the substring from the word, starting at 'start' and spanning 'end - start + 1' characters
                words.push_back(word.substr(start, end - start + 1));
            }
        }

        // Convert words to lowercase and store them in the member variable m_words
        m_words = words;
        for (auto &word: m_words) {
            std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) {
                return std::tolower(c);
            });
        }
        file.close();
        std::cout << "Test File Loaded For Spell Checking." << std::endl;
        return 0;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
}
//looks for words in BST if they're not found assume its misspelled and add to array
std::vector<std::string> spell_checker::spell_check() {
    std::vector<std::string> misspelled;
    for (const auto &word: m_words) {
        std::string lowercaseWord;
        for (char c: word) {
            lowercaseWord += std::tolower(c);
        }
        //search bst for word if not found assume misspelled and add it to vector
        if (!m_bst.search(lowercaseWord)) {
            misspelled.push_back(lowercaseWord);
        }
    }
    return misspelled;
}
