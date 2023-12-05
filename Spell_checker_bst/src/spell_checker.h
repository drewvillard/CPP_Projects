//
// Created by drew on 2023-11-17.
//

#ifndef ASSIGNMENT_3_SPELL_CHECKER_H
#define ASSIGNMENT_3_SPELL_CHECKER_H
#include "binary_search_tree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <regex>



class spell_checker {
public:
 spell_checker(std::string test_name, std::string output_file, std::string dictionary_file);
 void fill_BST();
 int load_test(std::string file_name);
 void BST_to_file(std::string file_name);
 std::vector<std::string> spell_check();
private:
    std::vector<std::string> m_words;
    // Create an instance of your binary_search_tree
    binary_search_tree m_bst;
    std::string m_dictionary_file;
};


#endif //ASSIGNMENT_3_SPELL_CHECKER_H
