#ifndef TEST_RANDOM_H
#define TEST_RANDOM_H

#include "test_base.h"
#include <string>

class TestRandom : public TestBase
{
    private:
        void test_limit();
        void test_throws();
        void test_int_range();

    public:
        TestRandom(): TestBase() {};

        void run_tests();

};


#endif