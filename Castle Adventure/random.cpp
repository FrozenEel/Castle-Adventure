#include "random.h"

#include <random>
#include <stdexcept>

namespace Random
{
    // Create a random device
    std::random_device m_rd;

    // Use the random device to seed a random number generator
    std::mt19937 m_rng(m_rd());

    // Generates random number between min and max, inclusive.
    int generateRandomInt(int min, int max)
    {
        if (max < min)
        {
            throw std::invalid_argument("max must be > min");
        }
        // Define a uniform distribution of integers between min and max, inclusive
        std::uniform_int_distribution<int> distribution(min, max);

        // Generate and return a random integer from the distribution
        return distribution(m_rng);
    }

    // Returns true with given probability
    bool returnTrueWithProbability(double probability)
    {
        if (probability > 1.0 || probability < 0.0)
        {
            throw std::invalid_argument("probability must be in range [0,1]");
        }
        // Define a Bernoulli distribution with the given probability
        std::bernoulli_distribution distribution(probability);

        // Generate and return a boolean value based on the distribution
        return distribution(m_rng);
    }

};