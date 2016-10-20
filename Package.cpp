#include <array>
#include "Package.hpp"


Package::Package(std::string destination, unsigned int weight) : destination(destination), weight(weight) {
}


std::string Package::getDestination() const {
    return destination;
}


int Package::getWeight() const {
    return weight;
}


Package::~Package() {

}


Hash::Hash(std::string destination, unsigned int weight)
        : Package(destination, weight) {}


Heroin::Heroin(std::string destination, unsigned int weight)
        : Package(destination, weight) {}


DonaldTrumpMerchandise::DonaldTrumpMerchandise(std::string destination, unsigned int weight)
        : Package(destination, weight) {}


LegalPackage::LegalPackage(std::string destination, unsigned int weight)
        : Package(destination, weight) {}
