#ifndef DRAGON_H
#define DRAGON_H

#include "monster.h"



class Dragon : public Monster {
public:
    Dragon() : Monster(50, 20, 20) {}

    void attack(Creature & creature) override {
    }

    void takeDamage(int damage) override {
    }

    const std::string getSpecies() const override{
        return "dragon";
    }
};


#endif