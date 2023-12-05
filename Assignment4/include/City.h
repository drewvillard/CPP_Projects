#ifndef _CITY_H
#define _CITY_H

#include <iostream>
#include "Organism.h"

using namespace std;

class Organism;

const int GRID_WIDTH = 20;
const int GRID_HEIGHT = 20;

class City
{
protected:
	Organism *grid[GRID_HEIGHT][GRID_WIDTH];

public:
	City();
	virtual ~City();

	Organism *getOrganism( int x, int y );
	void setOrganism( Organism *organism, int x, int y );

    int countTyoe(char);

	void move();

	friend ostream& operator<<( ostream &output, City &city );

    bool hasDiversity();

    void reset();

    int countOrganisms(Organism::OrganismType) const;

    bool isEmpty(int pos1, int pos2)const;

    void clearCell(int x, int y);
};

#endif

