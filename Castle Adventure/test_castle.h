#ifndef TEST_CASTLE_H
#define TEST_CASTLE_H

#include "test_base.h"

#include <string>

#include "castle.h"
#include "room.h"

class TestCastle : public TestBase
{
    private:
        void test_castle(Castle & castle);
        void test_room(Room & room);


    public:
        TestCastle(): TestBase() { };

        void run_tests() override;

};


#endif