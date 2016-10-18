//
// Created by dennis on 12/10/16.
//

#pragma once

#include <memory>
#include "Package.hpp"
#include "Checkpoint.hpp"

class BaggageGen {
public:
    BaggageGen(std::vector<ICheckpoint*> &vector);

    void start();
private:
    std::vector<std::shared_ptr<Package>> bagageList;
    std::vector<ICheckpoint*> checkIns;

    void readBaggageFromFile();
};
