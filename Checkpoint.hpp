#pragma once

#include <map>
#include <vector>
#include <iostream>
#include <boost/signals2.hpp>
#include <mutex>
#include "Package.hpp"


typedef std::string TDestinationAddress;


class ICheckpoint {
public:
    std::string getName() const;
    virtual void checkIn(TPackage package) = 0;
protected:
    ICheckpoint(std::string name = "") : name_(name) {}
    std::string name_;
};


class ICollectable {
    typedef boost::signals2::signal<void()> TSignal;
public:
    virtual TPackageVector& getContent() = 0;

    TSignal signal;
protected:
    std::mutex contentMutex_;
};


class RouteCheckpoint : public ICheckpoint {
public:
    RouteCheckpoint(ICheckpoint *nextCheckpoint) : nextCheckpoint_(nextCheckpoint) {}
    void checkIn(TPackage package);
    void addRoute(TDestinationAddress address, ICheckpoint *checkpoint);

protected:
    ICheckpoint *getRoute(TDestinationAddress address);
    void dispatch(TPackage package);
    void dispatch(TPackage package, ICheckpoint *checkpoint);
    bool hasRoute(TDestinationAddress address);

private:
    std::map<TDestinationAddress, ICheckpoint *> routes_;
    ICheckpoint *nextCheckpoint_;
};


class BaggageBox : public ICheckpoint, public ICollectable {
public:
    BaggageBox() {}

    BaggageBox(std::string name) : ICheckpoint(name) {}

    void checkIn(TPackage package);

    TPackageVector& getContent();
private:
    std::vector<TPackage> content_;
};
