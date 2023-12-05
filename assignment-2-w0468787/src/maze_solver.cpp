//
// Created by drew on 2023-10-19.
//

#include "maze_solver.h"
#include "queue.h"


// Constructor to initialize maze variables for use in solving
MazeSolver::MazeSolver(int size, const std::string &file_name) : m_maze_size(size), m_maze_file_name(file_name),
                                                                 m_x_start(1), m_y_start(0), m_x_end(49), m_y_end(48) {
}

// Destructor to deallocate memory
MazeSolver::~MazeSolver() {
    // Deallocate the visited array
    for (int i = 0; i < m_maze_size; ++i) {
        delete[] m_visited[i];
    }
    delete[] m_visited;
    //Deallocate maze
    for (int i = 0; i < m_maze_size; ++i) {
        delete[] m_maze[i];
    }
    delete[] m_maze;

}

void MazeSolver::init_visited() {
    m_visited = new bool *[m_maze_size];
    for (int i = 0; i < m_maze_size; ++i) {
        m_visited[i] = new bool[m_maze_size];
        for (int j = 0; j < m_maze_size; ++j) {
            m_visited[i][j] = false; // Mark all cells as not visited
        }
    }
}

// Function to read maze from file into member variable maze
bool MazeSolver::load_maze() {
    std::ifstream file(m_maze_file_name);

    if (file.is_open()) {
        std::string line;

        // Allocate memory for the 2D maze array
        m_maze = new char *[m_maze_size];
        for (int i = 0; i < m_maze_size; ++i) {
            m_maze[i] = new char[m_maze_size];
        }

        // Read maze data from the file and populate m_maze
        for (int i = 0; i < m_maze_size; ++i) {
            if (std::getline(file, line)) {
                for (int j = 0; j < m_maze_size && j < line.length(); ++j) {
                    m_maze[i][j] = line[j];
                }
            }
        }

        file.close();

        // Print the maze
        std::cout << "Maze Loaded:\n";
        for (int i = 0; i < m_maze_size; ++i) {
            for (int j = 0; j < m_maze_size; ++j) {
                std::cout << m_maze[i][j];
            }
            std::cout << std::endl;
        }

        return true;
    } else {
        std::cerr << "Error: Unable to open maze file." << std::endl;
        return false;
    }
}

bool MazeSolver::solve_maze() {
    //queues for solving (maze_queue) and backtracking respectively
    Queue maze_queue;
    Queue back_tracking_queue;
    maze_queue.push(m_x_start, m_y_start);

    // Possible moves: up, down, left, right
    // ordering is right, down, left, up
    int dx[] = {1, 0, -1, 0}; // Moves along columns (right and left)
    int dy[] = {0, 1, 0, -1}; // Moves along rows (up and down)

    init_visited();

    while (!maze_queue.empty()) {
        //create new current node tracking our current pos
        Node *current = new Node();
        current->m_x = maze_queue.peek_x();
        current->m_y = maze_queue.peek_y();

        int x = current->m_y;
        int y = current->m_x;

        // Reached the end position
        if (x == m_x_end && y == m_y_end) {
            m_maze[m_y_end][m_x_end] = '#'; // Mark the path with '*'
            print_maze();
            return true;
        }

        // If the current cell is not visited, mark it as visited and continue exploring
        if (!m_visited[y][x] || m_visited) {
            m_visited[y][x] = true;
            bool found_path = false;

            // Explore neighbors searching for empty cells
            for (int i = 0; i < 4; ++i) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];

                // Check if the new position is within the maze and an open path
                if (new_x >= 0 && new_x <= m_maze_size && new_y >= 0 && new_y <= m_maze_size &&
                    (m_maze[new_y][new_x] == ' ') && !m_visited[new_y][new_x]) {
                    //add position to back tracking queue to explore alternative paths
                    back_tracking_queue.push(new_x, new_y);
                    m_maze[new_y][new_x] = '#'; // marks path with # indicating route through maze
                    maze_queue.push(new_y, new_x);
                    found_path = true;
                    break;
                }
            }

            if (!found_path) {
                // Dead end, start backtracking
                while (!back_tracking_queue.empty()) {
                /*
                * If backtracked from the current position:
                * 1. Check if there are unexplored paths around the backtracked position.
                * 2. If unexplored paths exist, move back to the backtracked position and explore new paths.
                * 3. If no unexplored paths are found, mark the backtracked position as a dead end (' ') and continue
                * backtracking.
                */
                    auto back_tracked_pos = back_tracking_queue.back();
                    back_tracking_queue.pop_back();
                    int back_track_x = back_tracked_pos.second;
                    int back_track_y = back_tracked_pos.first;

                    // Check if there are unexplored paths around the backtracked position
                    if (has_unexplored_paths(back_track_x, back_track_y)) {

                        m_maze[y][x] = '$'; // Mark the current position as unexplored (' ')
                        x = back_track_x;
                        y = back_track_y;
                        maze_queue.push(x, y); // Add the backtracked position to the maze exploration queue
                        break;
                    }
                }
            }

        }

        maze_queue.pop();
    }

    // No path found
    std::cout << "maze unsolved\n\n";
    return false;
}

// Function to print the solved maze on user completion
void MazeSolver::print_maze() {
    std::cout << "\nMAZE SOLVED:\n\n";
    for (int i = 0; i < m_maze_size; ++i) {
        for (int j = 0; j < m_maze_size; ++j) {
            std::cout << m_maze[i][j];
        }
        std::cout << std::endl;
    }
    //prints maze to file (only called when maze completes)
    maze_to_file(m_maze);
}

bool MazeSolver::has_unexplored_paths(int x, int y) {

    // Possible moves: up, down, left, right
    // ordering is right, down, left, up
    int dx[] = {1, 0, -1, 0}; // Moves along columns (right and left)
    int dy[] = {0, 1, 0, -1}; // Moves along rows (up and down)

    // Check each neighbor to see if it's within the maze boundaries and is an unexplored path
    for (int i = 0; i < 4; ++i) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (new_x >= 0 && new_x < m_maze_size && new_y >= 0 && new_y < m_maze_size &&
            m_maze[new_y][new_x] == ' ' && !m_visited[new_y][new_x]) {
            return true; // Found an unexplored path
        }
    }

    return false; // No unexplored paths around the given position
}
void MazeSolver::maze_to_file(char **maze) {
    std::string base_file_path = "../solved/maze_solved";
    std::string file_extension = ".txt";
    std::string file_path = base_file_path + file_extension;

    int file_number = 1;
    // Keep incrementing file number until a non-existing file is found
    while (std::ifstream(file_path.c_str())) {
        file_path = base_file_path + "_" + std::to_string(file_number) + file_extension;
        file_number++;
    }

    std::ofstream outfile(file_path); // Open a new file for writing in the /solved/ directory
    if (outfile.is_open()) {
        // write the maze to the file
        for (int i = 0; i < m_maze_size; ++i) {
            for (int j = 0; j < m_maze_size; ++j) {
                outfile << maze[i][j];
            }
            outfile << std::endl;
        }

        std::cout << "Solved maze written to " << file_path << std::endl;

        outfile.close();
    } else {
        std::cerr << "Error: Unable to open " << file_path << " for writing." << std::endl;
    }
}
