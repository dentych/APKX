//
// Created by dennis on 12/10/16.
//

#pragma once

#include <memory>
#include "Package.hpp"
#include "XRay.hpp"

class Temp;

class BaggageGen {
public:
    BaggageGen(XRay* checkIn, std::string filePath) 
        : checkIn_(checkIn), filePath_(filePath) {}
    void start();
private:
    std::vector<TPackage> packageList;
    XRay* checkIn_;
    std::string filePath_;

    void readBaggageFromFile();
    void generatePackageType(Temp temp);
};

class Temp {
public:
    std::string type;
    std::string destination;
    unsigned int weight;
};

std::istream &operator>>(std::istream &is, Temp &temp);
