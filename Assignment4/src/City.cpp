//
// Created by drew on 2023-04-17.
//
#include "../include/City.h"
#include "../include/Organism.h"
#include "../include/GameSpecs.h"
#include "../include/Human.h"
#include "../include/Zombie.h"
#include <windows.h>
#include <conio.h>

City::City() {
    // Initialize the grid with nullptrs
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            grid[i][j] = nullptr;
        }
    }

    // Add initial zombies
    for (int i = 0; i < ZOMBIE_STARTCOUNT; i++) {
        int x = rand() % GRIDSIZE;
        int y = rand() % GRIDSIZE;
        while (grid[x][y] != nullptr) {
            x = rand() % GRIDSIZE;
            y = rand() % GRIDSIZE;
        }
        grid[x][y] = new Zombie(this,x, y);
    }

    // Add initial humans
    for (int i = 0; i < HUMAN_STARTCOUNT; i++) {
        int x = rand() % GRIDSIZE;
        int y = rand() % GRIDSIZE;
        while (grid[x][y] != nullptr) {
            x = rand() % GRIDSIZE;
            y = rand() % GRIDSIZE;
        }
        grid[x][y] = new Human(this,x, y);
    }
}

City::~City() {

}

Organism* City::getOrganism(int x, int y) {
    // Return the organism at the given position in the grid
    if (x >= 0 && x < GRID_HEIGHT && y >= 0 && y < GRID_WIDTH) {
        return grid[x][y];
    } else {
        return nullptr; // Return nullptr if the position is out of bounds
    }
}

void City::setOrganism(Organism* organism, int x, int y) {
    // Check if the space is empty before setting the organism
    if (grid[x][y] == nullptr && x >= 0 && x < GRID_HEIGHT && y >= 0 && y < GRID_WIDTH) {
        grid[x][y] = organism;
    }
}

void City::clearCell(int x, int y){
    grid[x][y]= nullptr;
}

void City::move() {
    for (int row = 0; row < GRIDSIZE; ++row) {
        for (int col = 0; col < GRIDSIZE; ++col) {
            Organism* organism = grid[row][col];

            // If the cell contains an organism and it hasn't moved this turn
            if (organism != nullptr && !organism->hasMoved()) {
                // Move the organism
                organism->move();
            }
        }
    }
}


ostream& operator<<(ostream& output, City& city) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            if (city.getOrganism(i, j) != nullptr) {
                Organism* organism = city.getOrganism(i, j);
                // Output the organism symbol
                if (organism->getType() == Organism::HUMAN) {
                    // Set the console text color
                    int color = static_cast<Human *>(city.getOrganism(i,j))->getColor();
                    SetConsoleTextAttribute(hConsole, color);
                    output << "H";
                } else if (organism->getType() == Organism::ZOMBIE) {
                    int color = static_cast<Zombie *>(city.getOrganism(i,j))->getColor();
                    SetConsoleTextAttribute(hConsole, color);
                    output << "Z";
                }
            } else {
                // Reset the console text color to default
                SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

                // Output the empty space symbol
                output << "-";
            }
        }
        output << endl;
    }

    // Reset the console text color to default
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    return output;
}

bool City::hasDiversity() {
    bool humansExist = false;
    bool zombiesExist = false;
    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
            if (grid[i][j] != nullptr) {
                if (grid[i][j]->getType() == Organism::HUMAN) {
                    humansExist = true;
                } else if (grid[i][j]->getType() == Organism::ZOMBIE) {
                    zombiesExist = true;
                }
            }
            if (humansExist && zombiesExist) {
                return true; // return early if both humans and zombies exist
            }
        }
    }
    return false; // no diversity found
}



// Function to reset "moved" flags of all organisms in the city
void City::reset() {
    for (int row = 0; row < GRIDSIZE; ++row) {
        for (int col = 0; col < GRIDSIZE; ++col) {
            if (grid[row][col] != nullptr) {
                grid[row][col]->setMoved(false);
            }
        }
    }
}

// Function to count the number of organisms of a given type in the city
int City::countOrganisms(Organism::OrganismType type) const {

    int count;
    for (int row = 0; row < GRIDSIZE; ++row) {
        for (int col = 0; col < GRIDSIZE; ++col) {
            if (grid[row][col] != nullptr && grid[row][col]->getType() == type) {
                count++;
            }
        }
    }
    return count;
}

bool City::isEmpty(int x, int y) const {
    // Check if the given position is within the city boundaries and the grid cell is empty
    if (x >= 0 && x < GRID_HEIGHT && y >= 0 && y < GRID_WIDTH && grid[x][y] == nullptr) {
        return true;
    }
    return false;
}

