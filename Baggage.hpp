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
    int counter;
    int weight;

    Baggage(int weight);
};

class Hash : public Baggage {
public:
    Hash(int weight);
};

class Heroin : public Baggage {
public:
    Heroin(int weight);
};

class DonaldTrumpMerchandise : public Baggage {
public:
    DonaldTrumpMerchandise(int weight);
};

class Package : public Baggage {
public:
    Package(int weight);
};
