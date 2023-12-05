//
// Created by drew on 2023-11-17.
//

#include "binary_search_tree.h"
#include <iostream>
#include <iomanip>

binary_search_tree::~binary_search_tree() {
    delete_tree(m_root);
}

void binary_search_tree::insert(const std::string &str) {
    insert(str, m_root);
}

void binary_search_tree::insert(const std::string &str, Node *&node) {
    if (node == nullptr) {
        // hit the bottom of the tree
        // end of the recursion
        node = new Node();
        node->m_data = str;
    } else if (str < node->m_data) {
        insert(str, node->m_left);

    } else if (str > node->m_data) {
        insert(str, node->m_right);

    } else {
        // inserting duplicate value
        std::cout << "Node value " << node->m_data << " already exists." << std::endl;
        return;
    }

    // Update height of the current node = to the max height of either subtree +1
    node->m_height = 1 + std::max(get_height(node->m_left), get_height(node->m_right));

    // Check balance factor
    int balance = get_balance(node);

    // if greater than 1 tree unbalanced (right subtree longer) and need to balance
    if (balance > 1 && str > node->m_right->m_data) {
        // Single left rotation
        node = rotate_left(node);
    }

}

int binary_search_tree::get_height(Node *node) {
    return (node != nullptr) ? node->m_height : 0;
}

// function gets balance factor of node
int binary_search_tree::get_balance(Node *node) {
    return (node != nullptr) ? (get_height(node->m_right) - get_height(node->m_left)) : 0;
}

// Helper function for single left rotation
Node *binary_search_tree::rotate_left(Node *node) {
    //set new root *x to right of node
    Node *x = node->m_right;
    //"new" BST node next to new root
    Node *T2 = x->m_left;

    // Set new roots left child to passed node and set the passed nodes(curr root) right child to created *t2
    x->m_left = node;
    node->m_right = T2;

    // Update heights
    node->m_height = 1 + std::max(get_height(node->m_left), get_height(node->m_right));
    x->m_height = 1 + std::max(get_height(x->m_left), get_height(x->m_right));

    // Return new root
    return x;
}

void binary_search_tree::delete_tree(Node *node) {

    if (node == nullptr) return;
    delete_tree(node->m_left);
    delete_tree(node->m_right);
    delete node;
}

void binary_search_tree::print_tree(std::ostream &output, Node *&node, int indent) {

    if (node != nullptr) {
        print_tree(output, node->m_right, indent + 20);
        output << std::setw(indent) << node->m_data << std::endl;
        print_tree(output, node->m_left, indent + 20);
    }
}

bool binary_search_tree::search(const std::string &value) const {
    // Start searching from the root
    Node *current = m_root;
    // Traverse the tree
    while (current != nullptr) {
        if (value == current->m_data) {
            // Found the value
            return true;
        } else if (value < current->m_data) {
            // Go left
            current = current->m_left;
        } else {
            // Go right
            current = current->m_right;
        }
    }
    // Value not found
    return false;
}

std::ostream &operator<<(std::ostream &output, binary_search_tree &bst) {
    bst.print_tree(output, bst.m_root, 0);
    return output;
}
