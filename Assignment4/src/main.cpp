//
// Created by W0068332 on 11/21/2021.
//
//Example main.cpp
//This supposes that city->step() calls the move method of each organism in the city
//in a single pass causing each to perform all tasks that it can.

#include <iostream>
#include <chrono>
#include <thread>
#include "../include/Organism.h"
#include "../include/City.h"
#include "../include/GameSpecs.h"

using namespace std;

void ClearScreen()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

int main() {
    int iterationCount=0;
    City *city = new City();
    const int INTERVAL=900;
    chrono:: milliseconds interval(INTERVAL);
    while (city->hasDiversity()&&iterationCount<ITERATIONS) { //while both humans and zombies exist
        this_thread::sleep_for(interval);
        ClearScreen();
        cout << *city; //prints city
        iterationCount++;
        cout<< "ITERATION: "<<iterationCount<<endl;
        cout << "HUMANS: " << city->countOrganisms(Organism::HUMAN) << endl;
        cout << "ZOMBIES: " << city->countOrganisms(Organism::ZOMBIE) << endl;
        city->move(); //includes all actions
        city->reset(); //resets moved flags

    }//end while
}//end main

