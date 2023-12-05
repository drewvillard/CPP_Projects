//
// Created by drew on 2023-04-17.
//
#include "../include/Organism.h"
#include "../include/City.h"

// Default constructor
Organism::Organism()
{
    // Default constructor implementation
    // Initialize data members to default values
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    moved = false;
    city = nullptr;
}

// Parameterized constructor
Organism::Organism(City* city, int width, int height)
{
    // Parameterized constructor implementation
    // Initialize data members with provided values
    x = 0;
    y = 0;
    this->width = width;
    this->height = height;
    moved = false;
    this->city = city;
}

// Destructor
Organism::~Organism()
{
    // Destructor implementation
    // Clean up any dynamically allocated resources, if any
    // For example, if there are any dynamically allocated objects or memory,
    // they should be deleted or released here
}

// Setter for position
void Organism::setPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

// Method to end turn
void Organism::endTurn()
{
    moved = false;
}

// Method to check if it's the organism's turn
bool Organism::isTurn()
{
    return !moved;
}

void Organism::setMoved(bool b) {
moved=b;
}

// Overloaded stream insertion operator for output
// Overloaded stream insertion operator for output
ostream& operator<<(ostream& output, const Organism& organism)
{
    // Output the desired information about the organism
    output << "Organism Information:";
    // Output any other relevant information
    return output;
}
void Organism::setType(OrganismType newType) {
    type = newType;
}

int Organism::getX() const {
    return x;
}

int Organism::getY() const {
    return y;
}
bool Organism::hasMoved(){
return moved;
}
