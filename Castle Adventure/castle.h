#ifndef CASTLE_H
#define CASTLE_H

#include <string>
#include <vector>
#include "room.h"

class Castle
{
    private:
        std::vector<Room*> m_rooms;
        bool m_quiet;

    public:
        Castle(bool quiet = false) : m_quiet{quiet}{}
        ~Castle();

        std::string toString() const;
        void generate();
        void save(const std::string & filename) const;

    // Allow our friendly associated test class access our private member variables
    friend class TestCastle;
};

#endif 