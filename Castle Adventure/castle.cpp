#include "castle.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "room.h"
#include "random.h"



Castle::~Castle()
{
    if (!m_quiet)
    {
        std::cout << "deleting castle" << std::endl;
    }

    
    for (auto & room : m_rooms)
    {
        delete room;
        room = nullptr;
    }
    m_rooms.clear();
    
}

void Castle::generate()
{
    // A castle has 15-20 rooms
    int numRooms = Random::generateRandomInt(15, 20);
    for (int i = 1; i <= numRooms; i++)
    {
        // Create a room object, and put it directly into our collection.
        if (!m_quiet)
        {
            std::cout << "...Generating room " << i << std::endl;
             
        }

        
    
        Room* newRoom = new Room(i, m_quiet);
        m_rooms.push_back(newRoom);


        
    }
}

std::string Castle::toString() const
{
    std::ostringstream ss;
    ss << "CastleInfo:" << std::endl;
    for (auto & r: m_rooms)
    {
        ss << r->toString() << std::endl;
    }
    return ss.str();
}


void Castle::save(const std::string & filename) const
{
    std::ofstream output_file(filename);
    if (!output_file)
    {
        throw std::runtime_error("Could not open file \"" + filename + "\".");
    }

   
     output_file << this->toString();

    output_file.close();
}
