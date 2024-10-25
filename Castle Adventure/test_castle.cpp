#include "test_castle.h"
#include <vector>
#include <map>
#include "test_base.h"
#include "castle.h"
#include "room.h"


// Each castle has between 15 and 20 rooms.
// Make sure the room number matches the expected room number.
// Make sure there is at least one monster in the castle.
void TestCastle::test_castle(Castle & castle)
{
    castle.generate();
    assert_true_quiet(castle.m_rooms.size() >= 15);
    assert_true_quiet(castle.m_rooms.size() <= 20);

    int expected_room_number = 1;
    size_t num_monsters_in_castle = 0;
    for (const auto &r : castle.m_rooms)
    {
        assert_true_quiet(r->getRoomNumber() == expected_room_number++);
        num_monsters_in_castle += r->getNumMonsters();
    }

    assert_true_quiet(num_monsters_in_castle > 0);
}

void TestCastle::test_room(Room & room)
{
    // There should be no more than room# monsters in this room
    assert_true_quiet(room.m_monsters.size() <= static_cast<size_t>(room.getRoomNumber()));
    for (auto m : room.m_monsters)
    {
        if (m->getSpecies() == "dragon")
        {
            assert_true_quiet(m->getHealth() == 50);
            assert_true_quiet(m->getAttackPower() == 20);
            assert_true_quiet(m->getDefensePower() == 20);
        }
        else if (m->getSpecies() == "goblin")
        {
            assert_true_quiet(m->getHealth() == 10);
            assert_true_quiet(m->getAttackPower() == 10);
            assert_true_quiet(m->getDefensePower() == 5);
        }
        else
        {
            assert_true(false); // If you add another monster, update this test
        }
    }
}



void TestCastle::run_tests()
{
    // since things are generated randomly, run test 1000 times
    for (int i=0; i < 1000 && getNumFailed() == 0; i++)
    {
        Castle c(true);
        test_castle(c);
        for (auto &room : c.m_rooms)
        {
            test_room(*room);
        }
    }
}