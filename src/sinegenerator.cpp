#include <cmath>
#include "matplotlibcpp.h"

#include "Samples.hpp"

namespace plt = matplotlibcpp;

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

int main() 
{
    Samples s1 = generateSine(2,0,50,500,2);
    Samples s2 = generateSine(2,M_PI/2,60,500,2);

   	plt::plot(s1.x, s1.y, "r");
   	plt::plot(s2.x, s2.y, "g");
	plt::show();
}
