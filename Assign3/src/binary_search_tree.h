//
// Created by drew on 2023-11-17.
//

#ifndef ASSIGNMENT_3_BINARY_SEARCH_TREE_H
#define ASSIGNMENT_3_BINARY_SEARCH_TREE_H


#pragma once
#include <cctype>
#include <iostream>

struct Node {
    std::string m_data;
    Node* m_left {nullptr};
    Node* m_right {nullptr};
    int m_height=1;

};

class binary_search_tree {
private:
    Node* m_root {nullptr};

public:
    virtual ~binary_search_tree();
    bool search(const std::string& value) const;
    void insert(const std::string& str);

private:
    void insert(const std::string& str, Node*& node);
    void delete_tree(Node* node);
    void print_tree(std::ostream& output, Node*& node, int indent);


    int get_height(Node* node);

    Node* rotate_left(Node* y);

    friend std::ostream& operator<<(std::ostream& output, binary_search_tree& bst);

    int get_balance(Node *node);
};

std::ostream& operator<<(std::ostream& output, binary_search_tree& bst);

#endif //ASSIGNMENT_3_BINARY_SEARCH_TREE_H
