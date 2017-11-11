#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "Samples.hpp"

void addNoise(Samples &s, double noiseA)
{
    std::srand(time(NULL));
    for(auto &i:s.y)
        i += noiseA * (0.5 - (double)std::rand() / RAND_MAX);
}

std::vector<double> xcorr(std::vector<double> &a, std::vector<double> &b)
{
    std::vector<double> xcorr(a.size() + b.size() - 1,0);
    for(int i = 0; i < xcorr.size(); ++i)
    {
        int n = i - b.size() + 1;
        std::cout<<"delay="<<n<<std::endl;
        for(int m = 0; m < a.size(); ++m)
        {
            if(m-n >= 0 && m-n < b.size())
            {
                xcorr.at(i) += a.at(m) * b.at(m-n);
                std::cout<<"xcorr["<<n<<"]=a["<<m<<"]*b["<<m+n<<"]"<<std::endl;
            } 
        }
     }
    return xcorr;
}
