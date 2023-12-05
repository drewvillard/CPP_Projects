    #ifndef _Zombie_H
    #define _Zombie_H

    #include "Organism.h"

    class Zombie : public Organism
    {
    public:
        Zombie();
        Zombie( City *city, int width, int height );
        virtual ~Zombie();


        void move();

        int getColor();
    private:
        int color;
        int moveCount;
        bool breedable;
        bool hasEaten;
    };

    #endif