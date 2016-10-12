#pragma once

#include <map>
#include <vector>
#include "meta.hpp"
#include "Baggage.hpp"


class ICheckpoint {
public:
    virtual void checkIn(Baggage* baggage) = 0;
};


class ICollectable {
public:
    virtual void collect() = 0;
};


class RouteCheckpoint : public ICheckpoint {
public:
    void checkIn(Baggage* baggage);
    void addRoute(unsigned int part, ICheckpoint* checkpoint);
protected:
    ICheckpoint* getRoute(unsigned int part);
    void dispatch(Baggage* baggage);
    void dispatch(Baggage* baggage, ICheckpoint* checkpoint);
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
    typedef TYPELIST3(Hash, Heroin, DonaldTrumpMerchandise) ContrabandTypes;
};


class BaggageBox : public ICheckpoint, public ICollectable {
public:
    void checkIn(Baggage* baggage);
    void collect();
private:
    std::vector<Baggage*> content_;
};
