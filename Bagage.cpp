//
// Created by dennis on 12/10/16.
//

#include "Bagage.hpp"

Bagage::Bagage() : counter(0) {
}

void Bagage::setDestination(int destination[]) {
    std::copy(std::begin(destination), std::end(destination), std::begin(this->destination));
}

int Bagage::nextPart() {
    if (counter < 0 || counter > array_size - 1) {
        return 0;
    }
    int value = destination[counter];
    counter++;
    return value;
}