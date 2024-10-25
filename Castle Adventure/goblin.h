#ifndef GOBLIN_H
#define GOBLIN_H

#include "monster.h"


class Goblin : public Monster {
public:
    Goblin() : Monster(10, 10, 5) {}

    void attack(Creature & creature) override {
    }

    void takeDamage(int damage) override {
    }

    const std::string getSpecies() const override{
        return "goblin";
    }
};

#endif