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
//    std::ifstream file("/home/dennis/Documents/git/APKX/packages.txt"); // DENNIS VERSION
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
        checkIn_->checkIn(std::shared_ptr<LegalPackage>(new LegalPackage(temp.destination, temp.weight)));
    } else if (temp.type == "Hash") {
        checkIn_->checkIn(std::shared_ptr<Hash>(new Hash(temp.destination, temp.weight)));
    } else if (temp.type == "Heroin") {
        checkIn_->checkIn(std::shared_ptr<Heroin>(new Heroin(temp.destination, temp.weight)));
    } else if (temp.type == "DonaldTrumpMerchandise") {
        checkIn_->checkIn(std::shared_ptr<DonaldTrumpMerchandise>(new DonaldTrumpMerchandise(temp.destination, temp.weight)));
    }
}

std::istream &operator>>(std::istream &is, Temp &temp) {
    return is >> temp.type >> temp.destination >> temp.weight;
}