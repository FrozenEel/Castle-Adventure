#include "test_random.h"

#include <iostream>
#include <stdexcept>

#include "random.h"

using namespace Random;

void TestRandom::test_limit()
{
    assert_true(generateRandomInt(0,0) == 0);
    assert_true(generateRandomInt(-1,-1) == -1);
    assert_true(!returnTrueWithProbability(0.0));
    assert_true(returnTrueWithProbability(1.0));
}

void TestRandom::test_throws()
{
    assert_expression_throws(std::invalid_argument, generateRandomInt(5, 2) );
    assert_expression_throws(std::invalid_argument, returnTrueWithProbability(-1.0) );
    assert_expression_throws(std::invalid_argument, returnTrueWithProbability(1.5) );
}

// Tests that each value in range is hit at least once
void TestRandom::test_int_range()
{
    const int BINS = 100;
    const unsigned long ITERATIONS = BINS * 1e5;
    bool hit[BINS] = {};
    int hits = 0;
    for (unsigned long i = 0 ; i < ITERATIONS; i++)
    {
        int rando = generateRandomInt(0, BINS-1);
        if (hit[rando] == false)
        {
            hit[rando] = true;
            hits++;
            if (hits == BINS)
            {
                TEST_PASS("integer range test passed");
                return;
            }
        }
    }
    TEST_FAIL("integer range test failed");
}

void TestRandom::run_tests()
{
    test_limit();
    test_throws();
    test_int_range();
}
