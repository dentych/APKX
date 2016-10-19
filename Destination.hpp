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
    void checkIn(std::shared_ptr<Package> baggage);
private:
    std::vector<std::shared_ptr<Package>> arrivedBaggage_;
    std::string name_;
};
