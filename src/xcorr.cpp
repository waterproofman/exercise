#include "Samples.hpp"

std::vector<double> xcorr(std::vector<double> &a, std::vector<double> &b)
{
    std::vector<double> xcorr(a.size() + b.size() - 1,0);
    for(int i = 0; i < xcorr.size(); ++i)
    {
        int n = i - b.size() + 1;
        for(int m = 0; m < a.size(); ++m)
        {
            if(m-n >= 0 && m-n < b.size())
            {
                xcorr.at(i) += a.at(m) * b.at(m-n);
            } 
        }
     }
    return xcorr;
}
