#include "room.h"

#include <iostream>
#include <sstream>
#include "random.h"
#include "monster.h"

Room::~Room()
{
    if (!m_quiet)
    {
        std::cout << "deleting room " << getRoomNumber() << std::endl;
    }
 

    for (auto & monster : m_monsters)
    {
        delete monster;
        monster = nullptr;
    }
    m_monsters.clear();

}

std::string Room::toString() const
{
    using namespace std;
    ostringstream ss;
    ss << "Room #" << getRoomNumber() << std::endl;
    for (auto & m: m_monsters)
    {
        ss << m->toString();
    }
    return ss.str();
}

void Room::generateMonsters()
{
    // rooms have 0-roomNumber chances to have a monster
    for (int i=0; i < getRoomNumber(); i++)
    {
       
        Monster* monster = Monster::Factory();

        if (monster != nullptr) {
            m_monsters.push_back(monster);
        }

        if (monster != nullptr)
        {
            std::cout << "      ...Adding " << monster->getSpecies() << " to room " << m_roomNumber << std::endl;
        }
       

        
    }
}
