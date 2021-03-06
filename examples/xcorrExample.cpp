#include <iostream>
#include "matplotlibcpp.h"
#include "sdsp.hpp"

namespace plt = matplotlibcpp;

int main()
{
    std::vector<double> a = {0.1,0.2,-0.1,4.1,-2,1.5,-0.1};
    std::vector<double> b = {0.1,4,-2.2,1.6,0.1,0.1,0.2};
    std::vector<double> xc = xcorr(a,b);
    for(auto i:xc)
        std::cout<<std::endl<<i;
    plt::plot(xc);
//    Samples s1 = generateSine(2,0,50,500,2);
//    Samples s2 = generateSine(2,M_PI/2,50,500,2);
//    TDSamples c = generateSine(1,100,500,1);
//   	TDSamples c = generateSine(x,y,1,52,5000,10);
//   	TDSamples c50 = generateSine(x,y,1,50,5000,10);
//   	addNoise(s,20);
//   	std::vector<double> xc = xcorr(s.y,c.y);
//   	std::vector<double> xc50 = xcorr(s.y,c50.y);

//   	plt::plot(s1.x, s1.y, "r");
//   	plt::plot(s2.x, s2.y, "g");
//   	plt::plot(xc, "b");
//   	plt::plot(xc50, "g.");
	plt::show();

/*
	srand (time(NULL));
	int n = 1000;
	std::vector<double> x(n), y(n), z(n), w(n);
	for(int i = 0; i < n; ++i) {
		x.at(i) = (i * 20 * M_PI)/n;
		y.at(i) = sin(x.at(i));
		z.at(i) = 5 - 10 * ((double)rand() / RAND_MAX);
		w.at(i) = y[i] + z[i];
	}

	// Plot line from given x and y data. Color is selected automatically.
	plt::plot(x, y,".");//, "-");
	//plt::plot(x, w,".");
	//plt::named_plot("sum",x,w,".");


	// Set x-axis to interval [0,1000000]
//	plt::xlim(0, 7000);//1000*1000);

	// Add graph title
	plt::title("Sample figure");
	// Enable legend.
	//plt::legend();
	plt::show();
	// save figure
//	plt::save("./basic.png");
*/
}
