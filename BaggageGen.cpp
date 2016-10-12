//
// Created by dennis on 12/10/16.
//

#include "BaggageGen.hpp"

BaggageGen::BaggageGen(ICheckpoint *checkIn) : checkIn(checkIn) {

}

BaggageGen::BaggageGen(std::shared_ptr<ICheckpoint> &checkIn) : checkIn(checkIn) {

}

void BaggageGen::nextBagage() {

}

