#include "matplotlibcpp.h"
#include "sdsp.hpp"

namespace plt = matplotlibcpp;

int main()
{
    Samples s1 = generateSine(2,0,50,500,2);
    Samples s2 = generateSine(2,M_PI/2,60,500,2);

   	plt::plot(s1.x, s1.y, "r");
   	plt::plot(s2.x, s2.y, "g");
	plt::show();
}
