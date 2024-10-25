#include "monster.h"

#include <sstream>

#include "creature.h"
#include "dragon.h"
#include "goblin.h"
#include "random.h"

Monster * Monster::Factory()
{
    // DONE Dragon - create a dragon 10% of the time.
    int ten_side_die = Random::generateRandomInt(1, 10);
    int four_side_die = Random::generateRandomInt(1, 4);
    if (ten_side_die == 1)
    {
        return new Dragon();
    }

    // DONE If we didn't create a dragon, create a Goblin 25% of the time
    if(four_side_die == 1){
        return new Goblin();
    }

    // Otherwise, return back nullptr, meaning no monsters this time
    return nullptr;
}

std::string Monster::toString() const
{
    // DONE return back the species name, followed by 
    // this objects's Creature toString() method to show health, attack, defense values
     return getSpecies() + " " + Creature::toString();

    // DONE This is just a stub; remove 
    return "";
}