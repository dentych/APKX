//
// Created by stud on 10/17/16.
//
#include "Package.hpp"
#include <vector>
#include <string>

#pragma once

typedef std::string TDestinationAddress;

class Destination {

public:
    Destination(std::string name);
    std::vector<Package*> arrivedBaggage;
    std::string getName();

private:
    std::string name_;

};