#include <iostream>
#include <string>
#include "maze_solver.h"

using namespace std;

int main(int argc, char *argv[]) {
    const int MAZE_SIZE = 51;
    //use command line argument to determine file to open
    try {
        if (argc > 1) {
            MazeSolver my_maze_solver(MAZE_SIZE, std::string(argv[1]));
            my_maze_solver.load_maze();
            my_maze_solver.solve_maze();
            my_maze_solver.print_maze();
        } else {
            std::cerr << "Error: Maze file name not provided." << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
    return 0;
}