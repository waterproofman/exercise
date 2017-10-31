#define _USE_MATH_DEFINES
#include <cmath>
#include "matplotlibcpp.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

namespace plt = matplotlibcpp;

struct Samples
{
    Samples(unsigned int size) : x(size), y(size)
    {
    }
    std::vector<double> x;
    std::vector<double> y;
};

Samples generateSine(double A, double phi, double fSignal, double fSampling, double nT)
{
    double Tsignal = 1.0 / fSignal;
    unsigned int n = ceil(fSampling * Tsignal * nT);
    Samples s(n);
    for(int i = 0; i < n; ++i)
    {
        s.x.at(i) = i / fSampling;
        s.y.at(i) = A * sin(s.x.at(i) * fSignal * 2 * M_PI + phi);
    }
	return s;
}

void addNoise(Samples &s, double noiseA)
{
    std::srand(time(NULL));
    for(auto &i:s.y)
        i += noiseA * (0.5 - (double)std::rand() / RAND_MAX);
}

int main() 
{
    Samples s1 = generateSine(2,0,50,500,2);
    Samples s2 = generateSine(2,M_PI/2,60,500,2);

   	plt::plot(s1.x, s1.y, "r");
   	plt::plot(s2.x, s2.y, "g");
	plt::show();
}
