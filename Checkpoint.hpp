#pragma once

#include <map>
#include <vector>
#include <iostream>
#include <boost/signals2.hpp>
#include "meta.hpp"
#include "Package.hpp"


typedef std::string TDestinationAddress;


class ICheckpoint {
public:
    virtual void checkIn(std::shared_ptr<Package> baggage) = 0;
};


class ICollectable {
    typedef boost::signals2::signal<void()> TSignal;
public:
    virtual std::vector<std::shared_ptr<Package>> collect() = 0;

    TSignal signal_;
};


class RouteCheckpoint : public ICheckpoint {
public:
    RouteCheckpoint(ICheckpoint *nextCheckpoint) : nextCheckpoint_(nextCheckpoint) {}

    void checkIn(std::shared_ptr<Package> baggage);

    void addRoute(TDestinationAddress address, ICheckpoint *checkpoint);

protected:
    ICheckpoint *getRoute(TDestinationAddress address);

    void dispatch(std::shared_ptr<Package> baggage);

    void dispatch(std::shared_ptr<Package> baggage, ICheckpoint *checkpoint);

    bool hasRoute(TDestinationAddress address);

private:
    std::map<TDestinationAddress, ICheckpoint *> routes_;
    ICheckpoint *nextCheckpoint_;
};


class XRay {
public:
    XRay(ICheckpoint *contrabandBox, ICheckpoint *checkpoint)
            : contrabandBox_(contrabandBox), checkpoint_(checkpoint) {}

    template<typename T>
    void checkIn(std::shared_ptr<T> baggage) {
        if (contains<ContrabandTypes, T>::value) {
            contrabandBox_->checkIn(baggage);
        } else {
            checkpoint_->checkIn(baggage);
        }
    }

private:
    ICheckpoint *contrabandBox_;
    ICheckpoint *checkpoint_;
};


class BaggageBox : public ICheckpoint, public ICollectable {
public:
    BaggageBox() {}

    BaggageBox(std::string name) : name_(name) {}

    void checkIn(std::shared_ptr<Package> baggage);

    std::vector<std::shared_ptr<Package>> collect();

private:
    std::vector<std::shared_ptr<Package>> content_;
    std::string name_;
};
