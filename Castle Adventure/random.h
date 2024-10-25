#ifndef RANDOM_H
#define RANDOM_H

namespace Random
{
    // Generates random number between min and max, inclusive.
    int generateRandomInt(int min, int max);

    // Returns true with given probability
    bool returnTrueWithProbability(double probability);
};
#endif