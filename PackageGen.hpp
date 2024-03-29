#pragma once

#include <memory>
#include <exception>
#include <stdexcept>
#include "Package.hpp"
#include "XRay.hpp"


class Temp {
public:
    std::string type;
    std::string destination;
    unsigned int weight;
};


class PackageGen {
public:
    PackageGen(XRay* checkIn, std::string filePath)
        : checkIn_(checkIn), filePath_(filePath) {}
    void start();
private:
    XRay* checkIn_;
    std::string filePath_;

    void readPackagesFromFile();
    void generatePackageType(Temp temp);
    
    template<typename T>
    std::shared_ptr<T> createPackage(Temp t) {
        return std::shared_ptr<T>(new T(t.destination, t.weight));
    };
};


class InvalidPackageTypeException : public std::runtime_error {
public:
    InvalidPackageTypeException(std::string typeName)
        : runtime_error("Invalid package type: " + typeName) {}
};


std::istream &operator>>(std::istream &is, Temp &temp);
