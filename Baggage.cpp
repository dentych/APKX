//
// Created by dennis on 12/10/16.
//

#include "Baggage.hpp"

Baggage::Baggage() : counter(0) {
}

void Baggage::setDestination(int destination[]) {
    std::copy(std::begin(destination), std::end(destination), std::begin(this->destination));
}

int Baggage::nextPart() {
    if (counter < 0 || counter > array_size - 1) {
        return 0;
    }
    int value = destination[counter];
    counter++;
    return value;
}