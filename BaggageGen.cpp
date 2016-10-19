//
// Created by dennis on 12/10/16.
//

#include <fstream>
#include <iterator>
#include <iostream>
#include <queue>
#include "BaggageGen.hpp"


void BaggageGen::start() {
    readBaggageFromFile();
}

void BaggageGen::readBaggageFromFile() {
    std::vector<Temp> tempList;
    std::ifstream file("packages.txt");
    std::istream_iterator<Temp> start(file);
    std::istream_iterator<Temp> eof;

    std::copy(start, eof, back_inserter(tempList));

    for (auto item : tempList) {
        generatePackageType(item);
    }
    for (auto item : packageList) {
        std::cout << typeid(item.get()).name() << std::endl;
        if (typeid(item.get()) == typeid(LegalPackage)) {
            std::cout << "This is legal!" << std::endl;
        }
        std::cout << "Dest: " << item->getDestination() << std::endl;
    }
}

void BaggageGen::generatePackageType(Temp temp) {
    if (temp.type == "LegalPackage") {
        checkIn_->checkIn(new LegalPackage(temp.destination, temp.weight));
    } else if (temp.type == "Hash") {
        checkIn_->checkIn(new Hash(temp.destination, temp.weight));
    } else if (temp.type == "Heroin") {
        checkIn_->checkIn(new Heroin(temp.destination, temp.weight));
    } else if (temp.type == "DonaldTrumpMerchandise") {
        checkIn_->checkIn(new DonaldTrumpMerchandise(temp.destination, temp.weight));
    }
}

std::istream &operator>>(std::istream &is, Temp &temp) {
    return is >> temp.type >> temp.destination >> temp.weight;
}