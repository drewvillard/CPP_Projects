//
// Created by drew on 2023-09-22.
//

#include "../include/linked_list.h"
#include <iostream>
#include <fstream>

//constructor
LinkedList::LinkedList() : m_start(nullptr) {}

//destructor
LinkedList::~LinkedList() {
    auto node = m_start;

    while (node != nullptr) {
        auto temp = node;
        node = node->m_next;
        delete temp->m_data;
        delete temp;
    }
}

//node destructor
LinkedList::LinkedListNode::~LinkedListNode() {
    if (m_data) {
        delete[] m_data;
    }
}

//adds node with specified id and data
void LinkedList::add(int id, char *data) {
    // create a new node
    auto node = new LinkedListNode(id, data);
    //node->m_data = data;
    m_cursor = node;

    if (m_start == nullptr) {
        // set initial node
        m_start = node;
    } else {
        // add other nodes
        auto curr = m_start;
        auto prev = (LinkedListNode *) nullptr;

        // find the end of the chain
        while (curr != nullptr) {
            prev = curr;
            curr = curr->m_next;
        }

        prev->m_next = node;
    }
}

//Inserts a new node containing the specified data before the node with the given ID
void LinkedList::insert(char *data, int before) {

    // when list is empty, call the add function
    if (m_start == nullptr) {
        return add(1, data);
    }

    // create a new node WITH CSTR COPY
    auto node = new LinkedListNode(before);
    node->m_data = new char[strlen(data) + 1];
    strcpy(node->m_data, data);

    // find node to insert before
    int index = 1;
    auto curr = m_start;
    auto prev = (LinkedListNode *) nullptr;

    while (curr != nullptr) {

        // find index to insert before
        if (index++ == before) {
            break;
        }

        prev = curr;
        curr = curr->m_next;
    }

    if (curr != nullptr) {

        // found node to insert before
        if (prev == nullptr) {
            // inserting at the start
            node->m_next = m_start;
            m_start = node;
        } else {
            // inserting in the middle
            node->m_next = prev->m_next;
            prev->m_next = node;
        }
    }
    // Update the IDs of the nodes
    curr = m_start;
    int id = 1; // Start with ID 1
    while (curr != nullptr) {
        curr->m_id = id++;
        curr = curr->m_next;
    }
}

void LinkedList::remove(int start_id = -1, int end_id = -1) {
    if (start_id <= 0 || end_id <= 0) {
        // If start_id or end_id is not provided or invalid, use the cursor position
        if (m_cursor == nullptr) {
            //cursor empty
            return;
        }
        start_id = end_id = m_cursor->m_id;
    }

    // Ensure start_id is less than or equal to end_id
    if (start_id > end_id) {
        std::swap(start_id, end_id);
    }

    auto curr = m_start;
    auto prev = (LinkedListNode *) nullptr;
    int index = 1;

    // Find the start node to delete
    while (curr != nullptr && index < start_id) {
        prev = curr;
        curr = curr->m_next;
        index++;
    }

    if (start_id == end_id) {
        if (curr != nullptr) {
            // Found the node to delete
            if (prev == nullptr) {
                // Deleting the first node
                m_start = curr->m_next;
            } else {
                prev->m_next = curr->m_next;
            }

            delete curr;
            m_cursor = prev;
        }
    } else {
        // Delete nodes in the specified range
        while (curr != nullptr && index <= end_id) {
            auto temp = curr;
            curr = curr->m_next;

            if (prev == nullptr) {
                // Deleting the first node
                m_start = curr;
            } else {
                prev->m_next = curr;
            }

            delete temp;
            index++;
        }
    }

    // Adjust m_id values after removal
    curr = m_start;
    index = 1;
    while (curr != nullptr) {
        curr->m_id = index++;
        curr = curr->m_next;
    }

}

int LinkedList::getCursorPosition() const {
    if (m_cursor == nullptr) {
        return -1;
    }

    // Calculate the cursor position based on the node's position in the list
    int position = 1;
    LinkedListNode *current = m_start;
    while (current != nullptr && current != m_cursor) {
        current = current->m_next;
        position++;
    }

    return m_cursor->m_id;
}

// Function uses the nodes of the linked list to shift the position of the cursor
void LinkedList::moveCursorTo(int position) {
    if (position <= 0) {
        m_cursor = nullptr;
        return;
    }

    auto curr = m_start;
    while (curr != nullptr && curr->m_id != position) {
        curr = curr->m_next;
    }

    m_cursor = curr;
}

//function moves through whole linked list leaving the cursor at the end
void LinkedList::moveCursorToEnd() {
    auto curr = m_start;
    LinkedListNode *prev = nullptr;

    // Traverse the list until the end
    while (curr != nullptr) {
        prev = curr;
        curr = curr->m_next;
    }

    m_cursor = prev;
}

//function tries to write to passed file using ofstream
void LinkedList::writeToFile(const std::string &fileName) const {
    std::ofstream file_out(fileName);

    if (file_out.is_open()) {
        LinkedListNode *current = m_start;

        // Iterate through the list and write each node's data to the file
        while (current != nullptr) {
            file_out << current->m_data << '\n';
            current = current->m_next;
        }

        file_out.close();
    }
}

//function is only called when user enters "L <int> <int>"
void LinkedList::printRange(int start_id, int end_id) const {
    auto curr = m_start;
    int index = 1;

    // Iterate through the list
    while (curr != nullptr && index <= end_id) {
        if (index >= start_id) {
            // Print the node if it's within the specified range
            std::cout << curr->m_id << ">" << curr->m_data << " " << std::endl;
        }

        curr = curr->m_next;
        index++;
    }
}

//common is empty function
bool LinkedList::isEmpty() const {
    return m_start == nullptr;
}

//overloaded operator outputs "line_num">" <node_data>"
std::ostream &operator<<(std::ostream &output, LinkedList &list) {
    auto node = list.m_start;

    // output all nodes in the list
    while (node != nullptr) {
        std::cout << node->m_id << ">" << node->m_data << " " << std::endl;
        node = node->m_next;
    }
    return output;
}

//common get size function
int LinkedList::getSize() {
    int count = 0;
    LinkedListNode *current = m_start;

    //loop to end of list
    while (current != nullptr) {
        count++;
        current = current->m_next;
    }

    return count;
}
