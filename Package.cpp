
//
// Created by dennis on 12/10/16.
//

#include <array>
#include "Package.hpp"

Package::Package(unsigned int weight) : counter(0), weight(weight) {
}

void Package::setDestination(std::array<int, array_size> destination) {
    std::copy(std::begin(destination), std::end(destination), std::begin(this->destination));
}

int Package::nextPart() {
    if (counter < 0 || counter > array_size - 1) {
        return 0;
    }
    int value = destination[counter++];

    return value;
}

int Package::getWeight() {
    return weight;
}

Hash::Hash(unsigned int weight) : Package(weight) {}

Heroin::Heroin(unsigned int weight) : Package(weight) {}

DonaldTrumpMerchandise::DonaldTrumpMerchandise(unsigned int weight) : Package(weight) {}

LegalPackage::LegalPackage(unsigned int weight) : Package(weight) {}