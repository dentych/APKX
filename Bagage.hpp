//
// Created by dennis on 12/10/16.
//

#pragma once

#include <string>
#include <vector>

class Bagage {
public:
    void setDestination(int destination[]);

    int nextPart();

protected:
    static const int array_size = 4;
    int destination[array_size];
    int counter;

    Bagage();
};

class Hash : Bagage {

};

class Heroin : Bagage {

};

class DonaldTrumpMerchandise : Bagage {

};

class Package : Bagage {

};
