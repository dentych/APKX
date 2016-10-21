#include "Destination.hpp"


void Destination::checkIn(TPackage package) {
    arrivedPackages_.push_back(package);
}

Destination::~Destination() {
    bool correctDelivery = true;
    for (auto iter : arrivedPackages_) {
        if (iter->getDestination() != name_) {
            correctDelivery = false;
            break;
        }
    }
    std::string correct = correctDelivery ? "yes" : "no";
    std::cout << "Arrived packages at " << name_ << ": " << arrivedPackages_.size() << ". Correct delivery: " << correct << std::endl;
}
