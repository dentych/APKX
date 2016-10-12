//
// Created by dennis on 12/10/16.
//

#pragma once

#include <string>
#include <vector>

class Baggage {
public:
    void setDestination(int destination[]);

    int nextPart();

protected:
    static const int array_size = 4;
    int destination[array_size];
    int counter;

    Baggage();
};

class Hash : Baggage {

};

class Heroin : Baggage {

};

class DonaldTrumpMerchandise : Baggage {

};

class Package : Baggage {

};
