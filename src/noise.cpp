#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <random>

#include "Samples.hpp"

void addNoise(Samples &s, double noiseA)
{
	static std::random_device r;
	std::default_random_engine e1(r());
	std::uniform_real_distribution<double> uniform_dist(-noiseA/2, noiseA/2);
    for(auto &i:s.y)
        i += uniform_dist(e1);
}
