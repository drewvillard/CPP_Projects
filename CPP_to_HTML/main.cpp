#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <ostream>
#include <exception>

//author drew villard w0468787

using namespace std;

void writeFile(string outFile);

void readFile(string inFile, ofstream &stream);

void customException();


void toHtml(string, string);

//Changes Remove finishedFile
string files;
string finishedFile;

int main() {
    //expected
    string exp(".");
    //drives the code that will run writeFile that will run readFile
    bool driver = false;
    while (true) {
        cout << "Input which cpp file you'd like to alter for HTML use (C:\\myFile.cpp) <- format" << endl;
        string file;
        getline(cin, file);
        cout << "Input which HTML file you'd like to store altered CPP file in (C:\\title.html format)" << endl;
        string htmlFile;
        getline(cin, htmlFile);
        for (int x = 0; x < file.length(); x++) {
            if (file[file.length() - 1] != 'p')
                driver = true;
            if (isalpha(file[x]))
                continue;
            if (file[x] == ' ')
                continue;
            if (file[x] == '\\')
                continue;
            if (file[x] == ':')
                continue;
            if (file[x == '.'])
                continue;
            else {
                driver = true;
            }
        }
        for (int x = 0; x < file.length(); x++) {
            if (htmlFile[htmlFile.length() - 1] != 'l')
                driver = true;
            if (isalpha(htmlFile[x]))
                continue;
            if (htmlFile[x] == ' ')
                continue;
            if (htmlFile[x] == '\\')
                continue;
            if (htmlFile[x] == ':')
                continue;
            if (htmlFile[x == '.'])
                continue;
            else {
                driver = true;
            }
        }
        if (!driver) {
            //changed catch to exception instead of char*
            string txtFile = htmlFile.substr(0, htmlFile.find(exp));
            string end = htmlFile.substr(htmlFile.find(exp) + 1);
            if (end == "html") {
                txtFile.append(".txt");
                files = file;
                //move toHtml into try catch and got the exceptions right so it will throw and not trigger toHtml
                try {
                    writeFile(txtFile);
                    toHtml(txtFile, htmlFile);
                } catch (exception msg) {
                    cout << msg.what() << endl;
                }


            } else {
                cout << "invalid HTML input" << endl;
            }
        } else {
            //added "on input"
            cout << "fail on input" << endl;
            driver = false;//reset

        }

    }
    return 0;
}

//edits cpp file to assignment specifications
//changed catch to throw exception to higher method
void writeFile(string outFile) {
    ofstream myFile;
    try {
        myFile.open(outFile, ios::out);

        if (!myFile.fail()) {
            if (myFile.is_open()) {
                myFile << "<PRE>\n";
                readFile(files, myFile);
                myFile << "</PRE>\n";
                myFile.close();
            }
        }
    } catch (exception e) {
        throw e;
    }
}

//reads lines from cpp file
void readFile(string inFile, ofstream &stream) {
    ifstream myFile;
    string line;
    //try to open file
    myFile.open(inFile, ios::in);

    //custom exception if file doesnt open or fails. Always throws and isn't fleshed out
    if (!myFile.is_open() || myFile.fail())
        customException();

    //if it doesnt fail
    if (!myFile.fail()) {
        if (myFile.is_open()) {
            //while not at end of file get next line
            while (!myFile.eof()) {
                getline(myFile, line);
                //for each character in file line
                for (char i: line) {
                    //if the character in the line is a > or < it will print &lt or &gt to the write file
                    string fileChar = string(1, i);
                    if (fileChar == "<") {
                        stream << "&lt";
                    } else if (fileChar == ">") {
                        stream << "&gt";
                    } else
                        stream << fileChar;
                }
                stream << "\r";
            }
        }
        myFile.close();
    }
}

//function converts the txt holding converted cpp to html
void toHtml(string original, string copy) {
    string line;
    ifstream toConvert(original);
    ofstream converted(copy);
    if (!toConvert.fail() && !converted.fail()) {
        while (getline(toConvert, line)) {
            converted << line << "\n";
        }
        cout << "html created \n";
    } else {
        throw "File not found";
    }
}
//struct for my exception extends std exception
struct MyException : public exception {
public:
    const string what() {
        return "File cannot be opened";
    }
};
//fixed exceptions to throw my exception using the created method
void customException() {
        throw MyException().what();
}