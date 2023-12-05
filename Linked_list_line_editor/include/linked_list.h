//
// Created by drew on 2023-09-22.
//
// linked_list.h

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <ostream>
#include <cstring>

class LinkedList {
private:
    // Inner struct representing a node in the linked list
    struct LinkedListNode {
        int m_id;
        char *m_data;
        LinkedListNode *m_next;

        LinkedListNode(int id, const char *data = nullptr) : m_id(id), m_next(nullptr) {
            if (data) {
                m_data = strdup(data);
            } else {
                m_data = nullptr;
            }
        }

        ~LinkedListNode();
    };


    LinkedListNode *m_start;
    LinkedListNode *m_cursor;
public:
    //constructor & destructor
    LinkedList();

    ~LinkedList();

    //class functions
    bool isEmpty() const;

    int getCursorPosition() const;

    void moveCursorTo(int position);

    void printRange(int start_id, int end_id) const;

    void add(int id, char *data);

    void insert(char *data, int before);

    void moveCursorToEnd();

    void remove(int start_id, int end_id);

    void writeToFile(const std::string &file_name) const;

    //friend function for overloaded output operator
    friend std::ostream &operator<<(std::ostream &output, LinkedList &list);

    int getSize();
};

#endif // LINKED_LIST_H