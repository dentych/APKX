#pragma once

#include <string>
#include <vector>
#include <array>
#include <memory>
#include "meta.hpp"


class Package {
public:
    static const int array_size = 4;

    std::string getDestination() const;

    int getWeight() const;

    virtual ~Package();

protected:
    std::string destination;
    unsigned int counter;
    unsigned int weight;

    Package(std::string destination, unsigned int weight);
};


class Hash : public Package {
public:
    Hash(std::string destination, unsigned int weight);
};


class Heroin : public Package {
public:
    Heroin(std::string destination, unsigned int weight);
};


class DonaldTrumpMerchandise : public Package {
public:
    DonaldTrumpMerchandise(std::string destination, unsigned int weight);
};


class LegalPackage : public Package {
public:
    LegalPackage(std::string destination, unsigned int weight);
};


typedef TYPELIST3(Hash, Heroin, DonaldTrumpMerchandise) ContrabandTypes;
typedef std::shared_ptr<Package> TPackage;
typedef std::vector<std::shared_ptr<Package>> TPackageVector;
