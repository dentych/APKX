#pragma once

#include <map>
#include <vector>
#include <iostream>
#include "meta.hpp"
#include "Package.hpp"


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
    void checkIn(Package *baggage);
    void addRoute(unsigned int part, ICheckpoint* checkpoint);
protected:
    ICheckpoint* getRoute(unsigned int part);
    void dispatch(Package* baggage);
    void dispatch(Package* baggage, ICheckpoint* checkpoint);
private:
    std::map<unsigned int, ICheckpoint*> routes_;
};


class XRay : public RouteCheckpoint {
public:
    XRay(ICheckpoint* contrabandBox) : contrabandBox_(contrabandBox) {}

    template<typename T>
    void checkIn(T* baggage) {
        if(contains<ContrabandTypes, T>::value)
            dispatch(baggage, contrabandBox_);
        else
            dispatch(baggage);
    }
private:
    ICheckpoint* contrabandBox_;
};


class BaggageBox : public ICheckpoint, public ICollectable {
public:
    void checkIn(Package *baggage);
    void collect();
private:
    std::vector<Package*> content_;
};
