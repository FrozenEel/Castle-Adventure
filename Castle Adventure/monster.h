#ifndef MONSTER_H
#define MONSTER_H

#include <string>

#include "creature.h"

class Monster : public Creature
{
    protected:
        Monster(int h, int a, int d): Creature(h, a, d) {}

    public:
        static Monster * Factory();
        std::string toString() const;

        virtual void attack(Creature & creature) = 0 ;
        virtual void takeDamage(int damage) = 0 ;
        virtual const std::string getSpecies() const = 0;
};
#endif