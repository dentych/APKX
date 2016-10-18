CXX=g++
CXXFLAGS=-std=c++11
EXECUTEABLE=john
SOURCES=main.cpp Baggage.cpp BaggageGen.cpp Checkpoint.cpp Collector.cpp Destination.cpp
DEPENDENCIES=$(SOURCES:.cpp=.o)
HEADERS=$(SOURCES:.cpp=.hpp)

all: $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) -o $(EXECUTEABLE) $(DEPENDENCIES)

%.d:%.cpp
	$(CXX) -MT$(@:.d=.o) -MM $(CXXFLAGS) $^ > $@

clean:
	rm -f $(DEPENDENCIES) $(EXECUTEABLE)

-include $(DEPS)
