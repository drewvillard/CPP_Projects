//
// Created by drew on 2023-10-19.
//

#ifndef ASSIGNMENT_2_MAZE_SOLVER_H
#define ASSIGNMENT_2_MAZE_SOLVER_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "queue.h"

class MazeSolver {
private:
    bool **m_visited; //2d bool array representing our visited cells
    char **m_maze; //  maze is a 2D array representing the maze
    int m_maze_size;
    std::string m_maze_file_name;
    const int m_x_start;
    const int m_y_start;
    const int m_x_end;
    const int m_y_end;

public:
    // Constructor to initialize maze and mazeSize
    MazeSolver(int size, const std::string &file_name);

    // Destructor to deallocate memory
    ~MazeSolver();

    // Function to read maze from file
    bool load_maze();

    // Function to solve the maze using a queue
    bool solve_maze();

    // Function to print the solved maze
    void print_maze();

    //Function to write the theoretically solved maze to output file
    void maze_to_file(char **maze);

    //initializes array to track visited coordinates
    void init_visited();

    //checks backtracked paths for more unexplored routes
    bool has_unexplored_paths(int x, int y);
};


#endif //ASSIGNMENT_2_MAZE_SOLVER_H
