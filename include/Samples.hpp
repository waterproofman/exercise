#include <vector>

struct Samples
{
    Samples(unsigned int size) : x(size), y(size)
    {
    }
    std::vector<double> x;
    std::vector<double> y;
};
namespace plt = matplotlibcpp;
