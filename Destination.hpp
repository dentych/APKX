#pragma once

#include "Package.hpp"
#include "Checkpoint.hpp"
#include <vector>
#include <string>

typedef std::string TDestinationAddress;


class Destination : public ICheckpoint {
public:
    Destination(std::string name) : name_(name) {}
    std::string getName();
    void checkIn(Package* baggage);
private:
    std::vector<Package*> arrivedBaggage_;
    std::string name_;
};
