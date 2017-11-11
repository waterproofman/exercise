SDSP_BIN_DIR := ./bin
SDSP_OBJ_DIR := $(SDSP_BIN_DIR)/obj
SDSP_SRC_FILES := $(wildcard src/*.cpp)
SDSP_OBJ_FILES := $(patsubst src/%.cpp,$(SDSP_OBJ_DIR)/%.o,$(SDSP_SRC_FILES))


all: sinegeneration xcorr

pre:
	 [ -s $(SDSP_BIN_DIR) ] || mkdir $(SDSP_BIN_DIR);
	 [ -s $(SDSP_OBJ_DIR) ] || mkdir $(SDSP_OBJ_DIR);

clean:
	rm bin -rf

libsdsp.a: $(SDSP_OBJ_FILES)
	ar rcs bin/$@ $^

#libsdsp: $(SDSP_OBJ_FILES)
#	g++ -o $@ $^

$(SDSP_OBJ_DIR)/%.o: src/%.cpp
	g++ $(CPPFLAGS) $(CXXFLAGS) -Iinclude -c -o $@ $<

xcorr: pre src/xcorr.cpp resources/matplotlibcpp.h libsdsp.a
	g++ -g examples/xcorrExample.cpp bin/libsdsp.a -I/usr/include/python2.7 -Iresources -Iinclude -lpython2.7 -o bin/xcorrExample

sinegeneration: pre examples/sineGeneration.cpp libsdsp.a
	g++ -g examples/sineGeneration.cpp bin/libsdsp.a -I/usr/include/python2.7 -Iinclude -Iresources -lpython2.7 -o bin/sineGeneration
