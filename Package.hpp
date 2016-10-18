//
// Created by dennis on 12/10/16.
//

#pragma once

#include <string>
#include <vector>
#include <array>
#include "meta.hpp"

class Package {
public:
    static const int array_size = 4;

    void setDestination(std::array<int, array_size>);

    int nextPart();

    int getWeight();

protected:
    std::array<int, array_size> destination;
    unsigned int counter;
    unsigned int weight;

    Package(unsigned int weight);
};

class Hash : public Package {
public:
    Hash(unsigned int weight);
};

class Heroin : public Package {
public:
    Heroin(unsigned int weight);
};

class DonaldTrumpMerchandise : public Package {
public:
    DonaldTrumpMerchandise(unsigned int weight);
};

class LegalPackage : public Package {
public:
    LegalPackage(unsigned int weight);
};

typedef TYPELIST3(Hash, Heroin, DonaldTrumpMerchandise) ContrabandTypes;