//
// Created by dennis on 12/10/16.
//

#include <array>
#include "Baggage.hpp"

Baggage::Baggage(int weight) : counter(0), weight(weight) {
}

void Baggage::setDestination(std::array<int, array_size> destination) {
    std::copy(std::begin(destination), std::end(destination), std::begin(this->destination));
}

int Baggage::nextPart() {
    if (counter < 0 || counter > array_size - 1) {
        return 0;
    }
    int value = destination[counter++];

    return value;
}

int Baggage::getWeight() {
    return weight;
}

Hash::Hash(int weight) : Baggage(weight) {}

Heroin::Heroin(int weight) : Baggage(weight) {}

DonaldTrumpMerchandise::DonaldTrumpMerchandise(int weight) : Baggage(weight) {}

Package::Package(int weight) : Baggage(weight) {}