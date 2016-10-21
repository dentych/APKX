#include "Destination.hpp"


void Destination::checkIn(TPackage package) {
    arrivedBaggage_.push_back(package);
}

Destination::~Destination() {
    bool correctDelivery = true;
    for (auto iter : arrivedBaggage_) {
        if (iter->getDestination() != name_) {
            correctDelivery = false;
            break;
        }
    }
}
