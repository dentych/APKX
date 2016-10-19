//
// Created by stud on 10/17/16.
//

#include "Destination.hpp"


std::string Destination::getName() {
    return name_;
}


void Destination::checkIn(Package *baggage) {
    std::cout << "Destination " << getName() << " received " << baggage->getDestination() << std::endl;
    arrivedBaggage_.push_back(baggage);
};
