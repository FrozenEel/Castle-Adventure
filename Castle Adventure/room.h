#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <string>
#include "monster.h"

class Room
{
    private:
        int  m_roomNumber;
        bool m_quiet;
        std::vector<Monster*> m_monsters;

        void generateMonsters();

    public:
        Room(int number, bool quiet) : m_roomNumber(number), m_quiet(quiet) { generateMonsters(); }
        ~Room();

        std::string toString() const;

       
        int getRoomNumber() const { return m_roomNumber; }
        int getNumMonsters()  { return m_monsters.size(); }


    friend class TestCastle;
};

#endif