//
// Created by dennis on 12/10/16.
//

#include <fstream>
#include <iterator>
#include <iostream>
#include <queue>
#include "PackageGen.hpp"


void PackageGen::start() {
    readPackagesFromFile();
}


void PackageGen::readPackagesFromFile() {
    std::vector<Temp> tempList;

    std::ifstream file(filePath_);
    std::istream_iterator<Temp> start(file);
    std::istream_iterator<Temp> eof;

    std::copy(start, eof, back_inserter(tempList));

    for (auto item : tempList) {
        try {
            generatePackageType(item);
        } catch (InvalidPackageTypeException e) {
            std::cout << "Ignoring invalid package: " << item.type << std::endl;
        }
    }

    checkIn_->stop();
}


void PackageGen::generatePackageType(Temp temp) {
    if (temp.type == "LegalPackage")
        checkIn_->checkIn(createPackage<LegalPackage>(temp));
    else if (temp.type == "Hash")
        checkIn_->checkIn(createPackage<Hash>(temp));
    else if (temp.type == "Heroin")
        checkIn_->checkIn(createPackage<Heroin>(temp));
    else if (temp.type == "DonaldTrumpMerchandise")
        checkIn_->checkIn(createPackage<DonaldTrumpMerchandise>(temp));
    else
        throw InvalidPackageTypeException(temp.type);
}


std::istream &operator>>(std::istream &is, Temp &temp) {
    return is >> temp.type >> temp.destination >> temp.weight;
}
