#pragma once

#include <map>
#include <vector>
#include <iostream>
#include "meta.hpp"
#include "Package.hpp"
#include "Destination.hpp"


class ICheckpoint {
public:
    virtual void checkIn(Package* baggage) = 0;
};


class ICollectable {
public:
    virtual void collect() = 0;
};


class RouteCheckpoint : public ICheckpoint {
public:
    RouteCheckpoint(ICheckpoint* nextCheckpoint) : nextCheckpoint_(nextCheckpoint) {}
    void checkIn(Package *baggage);
    void addRoute(TDestinationAddress address, ICheckpoint* checkpoint);
protected:
    ICheckpoint* getRoute(TDestinationAddress address);
    void dispatch(Package* baggage);
    void dispatch(Package* baggage, ICheckpoint* checkpoint);
    bool hasRoute(TDestinationAddress address);
private:
    std::map<TDestinationAddress, ICheckpoint*> routes_;
    ICheckpoint* nextCheckpoint_;
};


class XRay {
public:
    XRay(ICheckpoint* contrabandBox, ICheckpoint* checkpoint)
            : contrabandBox_(contrabandBox), checkpoint_(checkpoint) {}

    template<typename T>
    void checkIn(T* baggage) {
        if(contains<ContrabandTypes, T>::value)
            contrabandBox_->checkIn(baggage);
        else
            checkpoint_->checkIn(baggage);
    }
private:
    ICheckpoint* contrabandBox_;
    ICheckpoint* checkpoint_;
};


class BaggageBox : public ICheckpoint, public ICollectable {
public:
    void checkIn(Package *baggage);
    void collect();
private:
    std::vector<Package*> content_;
};
