#include "gtest/gtest.h"
#include "sdsp.hpp"

TEST(xcorr, Positive1)
{
    std::vector<double> a = {0.1, 0.2, -0.1, 4.1, -2, 1.5, -0.1};
    std::vector<double> b = {0.1, 4, -2.2, 1.6, 0.1, 0.1, 0.2};
    std::vector<double> out = {0.02, 0.05, 0.01, 0.99, 0.1, 0.31, 7.52, -12.46, 23.18, -11.05, 6.02, -0.25, -0.01};
    std::vector<double> xc = xcorr(a,b);
    for(int i = 0; i < xc.size(); i++)
    {
    	EXPECT_DOUBLE_EQ(xc[i], out[i]);
    }
    EXPECT_EQ(xcorr(a,b).size(), a.size() + b.size() -1);
}

