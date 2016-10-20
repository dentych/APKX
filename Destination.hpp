#pragma once

#include <vector>
#include <string>
#include "Package.hpp"
#include "Checkpoint.hpp"

typedef std::string TDestinationAddress;


class Destination : public ICheckpoint {
public:
    Destination(std::string name) : ICheckpoint(name) {}

    ~Destination();

    void checkIn(TPackage baggage);
private:
    std::vector<TPackage> arrivedBaggage_;
};
