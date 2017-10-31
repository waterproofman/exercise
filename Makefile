exercise: sinegenerator xcorr

xcorr: xcorr.cpp matplotlibcpp.h
	g++ xcorr.cpp -I/usr/include/python2.7 -lpython2.7 -o xcorr

sinegenerator: sinegenerator.cpp matplotlibcpp.h
	g++ sinegenerator.cpp -I/usr/include/python2.7 -lpython2.7 -o sinegenerator


