#include "Destination.hpp"


void Destination::checkIn(TPackage baggage) {
    std::cout << "Destination " << getName() << " received " << baggage->getDestination() << std::endl;
    arrivedBaggage_.push_back(baggage);
}

Destination::~Destination() {
    bool correctDelivery = true;
    for (auto iter : arrivedBaggage_) {
        if (iter->getDestination() != name_) {
            correctDelivery = false;
            break;
        }
    }
    std::string correct = correctDelivery ? "yes" : "no";
    std::cout << "Arrived packages at " << name_ << ": " << arrivedBaggage_.size() << ". Correct delivery: " << correct << std::endl;
}
