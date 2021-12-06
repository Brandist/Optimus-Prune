ARCH :=
CROSS := 
CXX :=  $(CROSS)g++
CXXFLAGS := -O0 -g -ggdb -std=gnu++11 -fopenmp

all:gpsdemo

gpsdemo:main.cpp 
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm gpsdemo
