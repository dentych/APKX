//
// Created by stud on 10/17/16.
//
#include "Baggage.hpp"
#include <vector>
#include <string>

#pragma once

class Destination {

public:
    Destination(std::string name);
    std::vector<Baggage*> arrivedBaggage;
    std::string getName();

private:
    std::string name_;

};