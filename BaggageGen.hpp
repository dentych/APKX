//
// Created by dennis on 12/10/16.
//

#pragma once

#include <memory>
#include "Baggage.hpp"
#include "Checkpoint.hpp"

class BaggageGen {
public:
    BaggageGen(ICheckpoint *checkIn);

    BaggageGen(std::shared_ptr<ICheckpoint> &checkIn);

    void nextBagage();

    void readBagage();
private:
    std::vector<std::shared_ptr<Baggage>> bagageList;
    std::shared_ptr<ICheckpoint> checkIn;
};
