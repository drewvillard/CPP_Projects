#include <iostream>
#include "spell_checker.h"

int main(int argc, char **argv) {
    try {
        // Check if there are enough command-line arguments
        if (argc < 3) {
            throw std::invalid_argument("Usage: " + std::string(argv[0])
                                        + " <test_file>.txt <binary_search_tree_output_file>.txt <dictionary_file>.txt");
        }

        // Create a spell_checker instance
        spell_checker checker(argv[1], argv[2],argv[3]);

        // Your spell_checker constructor should handle the dictionary file

        return 0;
    } catch (const std::exception &e) {
        // Handle exceptions
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}