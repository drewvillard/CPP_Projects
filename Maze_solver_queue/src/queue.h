//
// Created by drew on 2023-10-19.
//

#ifndef ASSIGNMENT_2_QUEUE_H
#define ASSIGNMENT_2_QUEUE_H


#include <iostream>

//Node contains x and y coordinates for maze positioning
struct Node {
    int m_x;
    int m_y;
    Node *m_next;
};

class Queue {
private:
    Node *m_first;
    Node *m_last;

public:
    Queue(); // Constructor
    ~Queue(); // Destructor

    //pushes node to end of queue
    void push(int x, int y);

    //gets first nodes x coordinate
    int peek_x();

    //gets first nodes y coordinate
    int peek_y();

    //removes first node in queue
    void pop();

    //checks if the queue is empty
    bool empty() const;

    //returns the x and y coordinates from the last node in queue as a pair
    std::pair<int, int> back() const;

    //removes the last node in the queue
    void pop_back();

    // friend function without implementation overloaded output
    friend std::ostream &operator<<(std::ostream &output, const Queue &queue);
};


#endif //ASSIGNMENT_2_QUEUE_H
