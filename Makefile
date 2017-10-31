exercise: xcorr

#minimal: examples/minimal.cpp matplotlibcpp.h
#	cd examples && g++ -DWITHOUT_NUMPY minimal.cpp -I/usr/include/python2.7 -lpython2.7 -o minimal -std=c++11

xcorr: xcorr.cpp matplotlibcpp.h
	g++ xcorr.cpp -I/usr/include/python2.7 -lpython2.7 -o xcorr


