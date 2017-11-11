#include <cmath>
#include <stdlib.h>
#include <time.h>

#include "Samples.hpp"

static bool callMeOnce()
{
    std::srand(time(NULL));
    return true;
}

void addNoise(Samples &s, double noiseA)
{
	static bool alreadyRandomized = callMeOnce();
    for(auto &i:s.y)
        i += noiseA * (0.5 - (double)std::rand() / RAND_MAX);
}
