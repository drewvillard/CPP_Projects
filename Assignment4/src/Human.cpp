#include "../include/Human.h"
#include "../include/City.h" // Include City.h for accessing the full definition of City class
#include <vector>

Human::Human()
{
    setType(HUMAN);
    color=HUMAN_COLOR;
    moveCount=0;
}

Human::Human(City* city, int width, int height) : Organism(city, width, height)
{
    // Constructor implementation
    setType(HUMAN);
    color=HUMAN_COLOR;
    moveCount=0;
}

Human::~Human()
{
    // Destructor implementation
}

void Human::move()
{
    // Move implementation for Human class

    int direction = rand() % NUM_DIRECTIONS; // Generate random direction
    switch (direction)
    {
        case WEST:
            if (width >= 0 ) { // Check if move is within city boundaries and not onto an occupied space

                city->setOrganism(this,width-1, height);
                width--;
                setMoved(true);
            }
            break;
        case NORTH:
            if (height > 0&&height<GRID_HEIGHT) { // Check if move is within city boundaries and not onto an occupied space

                city->setOrganism(this, width, height-1);
                height--;
                setMoved(true);
            }
            break;
        case EAST:
            if (width < GRID_WIDTH - 1) { // Check if move is within city boundaries and not onto an occupied space

                city->setOrganism(this, width+1, height);
                width++;
                setMoved(true);
            }
            break;
        case SOUTH:
            if (height < GRID_HEIGHT - 1) { // Check if move is within city boundaries and not onto an occupied space

                city->setOrganism(this, width, height+1);
                height++;
                setMoved(true);
            }
            break;
    }

    // Increment the move counter
    this->moveCount++;

    // Check if the Human should breed
    if (moveCount >= HUMAN_BREED) {
        // Find an empty adjacent space to breed
        std::vector<pair<int, int>> emptySpaces;
        if (x > 0 && city->isEmpty(x-1, y)) { // Check if adjacent space to the West is empty
            emptySpaces.push_back(std::make_pair(x-1, y));
        }
        if (y > 0 && city->isEmpty(x, y-1)) { // Check if adjacent space to the North is empty
            emptySpaces.push_back(std::make_pair(x, y-1));
        }
        if (x < width - 1 && city->isEmpty(x+1, y)) { // Check if adjacent space to the East is empty
            emptySpaces.push_back(std::make_pair(x+1, y));
        }
        if (y < height - 1 && city->isEmpty(x, y+1)) { // Check if adjacent space to the South is empty
            emptySpaces.push_back(std::make_pair(x, y+1));
        }

        // Randomly choose one of the empty spaces to breed
        if (!emptySpaces.empty()) {
            int randomIndex = rand() % emptySpaces.size();
            int newX = emptySpaces[randomIndex].first;
            int newY = emptySpaces[randomIndex].second;
            city->setOrganism(new Human(), newX, newY);
        }
        moveCount = 0; // Reset the move counter after breeding
    }
}

int Human::getColor() const {
    return color;
}





