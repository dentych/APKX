#include "Destination.hpp"


std::string Destination::getName() {
    return name_;
}


void Destination::checkIn(TPackage baggage) {
    std::cout << "Destination " << getName() << " received " << baggage->getDestination() << std::endl;
    arrivedBaggage_.push_back(baggage);
};
