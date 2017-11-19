#include "gtest/gtest.h"
#include "sdsp.hpp"

TEST(xcorr, Positive)
{
    std::vector<double> a = {0.1, 0.2, -0.1, 4.1, -2, 1.5, -0.1};
    std::vector<double> b = {0.1, 4, -2.2, 1.6, 0.1, 0.1, 0.2};
    std::vector<double> out = {0.02, 0.05, 0.01, 0.99, 0.1, 0.31, 7.52, -12.46, 23.18, -11.05, 6.02, -0.25, -0.1};
    EXPECT_EQ(xcorr(a,b), out);
    EXPECT_EQ(xcorr(a,b).size(), 13);
}

