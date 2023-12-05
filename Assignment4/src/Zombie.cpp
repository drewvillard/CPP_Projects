//
// Created by drew on 2023-04-17.
//
#include "../include/Zombie.h"
#include "../include/City.h"
#include <vector>

Zombie::Zombie()
{
    // Default constructor implementation
    setType(ZOMBIE);
    color = ZOMBIE_COLOR;
    moveCount=0;
    breedable= false;
    hasEaten= false;

}

Zombie::Zombie(City* city, int width, int height) : Organism(city, width, height) {
    setType(ZOMBIE);
    color=ZOMBIE_COLOR;
    moveCount=0;
    breedable=false;
    hasEaten= false;
}


Zombie::~Zombie()
{
    // Destructor implementation
}

void Zombie::move() {
    // Move implementation for Zombie class

    // Generate random direction
    int direction = rand() % 8 + 1;

    // Check if there is a human in an adjacent cell (including diagonal)
    std::vector<std::pair<int, int>> adjacentCells;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int newX = width + i;
            int newY = height + j;
            if (i != 0 || j != 0) { // Exclude the current cell
                if (newX >= 0 && newX < GRID_WIDTH && newY >= 0 &&
                    newY < GRID_HEIGHT) { // Check if cell is within city boundaries
                    Organism *org = city->getOrganism(newX, newY);
                    if (org != nullptr && org->getType() == HUMAN) { // Check if cell contains a human
                        adjacentCells.push_back(std::make_pair(newX, newY));
                    }
                }
            }
        }
    }

    if (!adjacentCells.empty()) {
        // Move to a random cell containing a human
        int randomIndex = rand() % adjacentCells.size();
        int newX = adjacentCells[randomIndex].first;
        int newY = adjacentCells[randomIndex].second;
        Organism *org = city->getOrganism(newX, newY);
        if (org != nullptr && org->getType() == Organism::HUMAN) { // check if there is a human at the target location
            // convert the human to a zombie
            city->clearCell(newX,newY);
            city->setOrganism(this, newX, newY);
            city->clearCell(width,height);
            hasEaten= true;
        } else {
            // set the zombie at the target location
            city->setOrganism(new Zombie(), newX, newY);

        }
        width = newX;
        height = newY;
        setMoved(true);

    } else {
        // Move to a random empty cell
        switch (direction) {
            case 1://west
                if (width >= 0 && city->isEmpty(width - 1,
                                                height)) { // Check if move is within city boundaries and onto an empty space
                    city->setOrganism(this, width - 1, height);
                    width--;
                    setMoved(true);
                }
                break;
            case 2://NW
                if (width >= 0 && height > 0 && city->isEmpty(width - 1, height -
                                                                         1)) { // Check if move is within city boundaries and onto an empty space
                    city->setOrganism(this, width - 1, height - 1);
                    width--;
                    height--;
                    setMoved(true);
                }
                break;
            case 3://North
                if (height > 0 && city->isEmpty(width, height -
                                                       1)) { // Check if move is within city boundaries and onto an empty space
                    city->setOrganism(this, width, height - 1);
                    height--;
                    setMoved(true);
                }
                break;
            case 4://NE
                if (width < GRID_WIDTH - 1 && height > 0 && city->isEmpty(width + 1, height -
                                                                                     1)) { // Check if move is within city boundaries and onto an empty space
                    city->setOrganism(this, width + 1, height - 1);
                    width++;
                    height--;
                    setMoved(true);
                }
                break;
            case 5://E
                if (width < GRID_WIDTH - 1 && city->isEmpty(width + 1,
                                                            height)) { // Check if move is within city boundaries and onto an empty space
                    city->setOrganism(this, width + 1, height);
                    width++;
                    setMoved(true);
                }
                break;
            case 6://SE
                if (width < GRID_WIDTH - 1 && height < GRID_HEIGHT - 1 &&
                    city->isEmpty(width + 1, height + 1)) {// Check
                    city->setOrganism(this, width + 1, height+1);
                    width++;
                    height++;
                    setMoved(true);
                }
                break;
            case 7://south
                if (width < GRID_WIDTH - 1 && height < GRID_HEIGHT - 1 &&
                    city->isEmpty(width, height + 1)) {// Check
                    city->setOrganism(this, width, height+1);
                    height++;
                    setMoved(true);
                }
                break;
            case 8://SW
                if (width < GRID_WIDTH - 1 && height < GRID_HEIGHT - 1 &&
                    city->isEmpty(width - 1, height + 1)) {// Check
                    city->setOrganism(this, width + 1, height+1);
                    width--;
                    height++;
                    setMoved(true);
                }
                break;
        }
    }

    //breed attempt
    moveCount++;
    if (moveCount>=ZOMBIE_BREED&&hasEaten){
    breedable =true;
    }
    if (!adjacentCells.empty()&&breedable) {
        // Move to a random cell containing a human
        int randomIndex = rand() % adjacentCells.size();
        int newX = adjacentCells[randomIndex].first;
        int newY = adjacentCells[randomIndex].second;
        Organism *org = city->getOrganism(newX, newY);
        if (org != nullptr && org->getType() == Organism::HUMAN) { // check if there is a human at the target location
            // convert the human to a zombie
            city->clearCell(newX,newY);
            city->setOrganism(this, newX, newY);
            city->clearCell(width, height); // clear the current cell
            width = newX;
            height = newY;
            hasEaten = true;
        } else {
            // set the zombie at the target location
            city->setOrganism(new Zombie(), newX, newY);
            city->clearCell(width, height); // clear the current cell
            width = newX;
            height = newY;
        }
        setMoved(true);
    }
}

int Zombie::getColor() {
    return ZOMBIE_COLOR;
}
