//
// Created by dennis on 12/10/16.
//

#pragma once

#include <string>
#include <vector>

class Baggage {
public:
    static const int array_size = 4;

    void setDestination(std::array<int, array_size>);

    int nextPart();

    int getWeight();

protected:
    std::array<int, array_size> destination;
    unsigned int counter;
    unsigned int weight;

    Baggage(unsigned int weight);
};

class Hash : public Baggage {
public:
    Hash(unsigned int weight);
};

class Heroin : public Baggage {
public:
    Heroin(unsigned int weight);
};

class DonaldTrumpMerchandise : public Baggage {
public:
    DonaldTrumpMerchandise(unsigned int weight);
};

class Package : public Baggage {
public:
    Package(unsigned int weight);
};
