//
// Created by dennis on 12/10/16.
//

#include "BaggageGen.hpp"

BaggageGen::BaggageGen(std::vector<ICheckpoint*> &checkIns) : checkIns(checkIns) {

}

void BaggageGen::start() {
    readBaggageFromFile();
}

void BaggageGen::readBaggageFromFile() {

}
