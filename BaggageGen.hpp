//
// Created by dennis on 12/10/16.
//

#pragma once

#include <memory>
#include "Package.hpp"
#include "Checkpoint.hpp"

class Temp;

class BaggageGen {
public:
    BaggageGen(std::vector<ICheckpoint*> &vector);

    void start();
private:
    std::vector<std::shared_ptr<Package>> packageList;
    std::vector<ICheckpoint*> checkIns;

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
