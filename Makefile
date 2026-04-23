CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

code: main.cpp src.hpp
	$(CXX) $(CXXFLAGS) main.cpp -o code

clean:
	rm -f code *.o
