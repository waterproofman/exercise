exercise:  sinegenerator xcorr

pre:
	test bin || mkdir bin

xcorr: pre src/xcorr.cpp resources/matplotlibcpp.h
	g++ -g src/xcorr.cpp -I/usr/include/python2.7 -Iresources -lpython2.7 -o bin/xcorr

sinegenerator: pre src/sinegenerator.cpp resources/matplotlibcpp.h
	g++ -g src/sinegenerator.cpp -I/usr/include/python2.7 -Iresources -lpython2.7 -o bin/sinegenerator
