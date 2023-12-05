//
// Created by drew on 2023-10-19.
//
#include "queue.h"


// Constructor
Queue::Queue() : m_first(nullptr), m_last(nullptr) {}

// Destructor
Queue::~Queue() {
    while (!empty()) {
        pop();
    }
}

void Queue::push(int x, int y) {
    auto node = new Node{x, y, nullptr};
    if (empty()) {
        m_first = node;
    } else {
        m_last->m_next = node;
    }
    m_last = node;
}
//returns front most nodes x coordinate
int Queue::peek_x() {
    if (m_first != nullptr) {
        return m_first->m_x;
    }
    return -1; // Return -1 for an empty queue
}

// Function to get the y-coordinate of the front node to set current and drive through maze
int Queue::peek_y() {
    if (m_first != nullptr) {
        return m_first->m_y;
    }
    return -1; // Return -1 for an empty queue
}

//FIFO pop queue method
void Queue::pop() {
    if (m_first != nullptr) {
        auto node = m_first;
        m_first = node->m_next;
        delete node;
        if (m_first == nullptr) {
            m_last = nullptr;
        }
    }
}

//used to tell if queue is empty determining whether the maze was solved
bool Queue::empty() const {
    return m_first == nullptr;
}

//overloaded output operator
std::ostream &operator<<(std::ostream &output, const Queue &queue) {
    auto node = queue.m_first;
    while (node != nullptr) {
        output << node;
        node = node->m_next;
    }
    return output;
}

//This Violates how queues should work but its a method to return the last node
std::pair<int, int> Queue::back() const {
    if (m_last != nullptr) {
    }
    return std::make_pair(m_last->m_x, m_last->m_y);
}

//another queue violation maybe but method removes last node used for backtrack purposes
void Queue::pop_back() {
    if (m_first == nullptr) {
        // Queue is empty, nothing to remove
        return;
    }

    if (m_first == m_last) {
        // Only one node in the queue
        delete m_first;
        m_first = nullptr;
        m_last = nullptr;
    } else {
        // Traverse the queue to find the second-to-last node
        Node *current = m_first;
        while (current->m_next != m_last) {
            current = current->m_next;
        }
        // Remove the last node
        delete m_last;
        m_last = current;
        m_last->m_next = nullptr;
    }
}