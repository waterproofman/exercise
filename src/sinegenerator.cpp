#include <cmath>

#include "Samples.hpp"

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


