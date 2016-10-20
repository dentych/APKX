CXX=g++
CXXFLAGS=-std=c++11 -pthread
EXECUTEABLE=john
SOURCES=$(wildcard *.cpp)
DEPENDENCIES=$(SOURCES:.cpp=.o)
HEADERS=$(SOURCES:.cpp=.hpp)

all: $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) -o $(EXECUTEABLE) $(DEPENDENCIES)

%.d:%.cpp
	$(CXX) -MT$(@:.d=.o) -MM $(CXXFLAGS) $^ > $@

clean:
	rm -f $(DEPENDENCIES) $(EXECUTEABLE)
	rm -f *.gch

-include $(DEPS)
