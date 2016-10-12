#pragma once

#include <map>
#include <vector>
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
    void addRoute(int part, ICheckpoint* checkpoint);
protected:
    ICheckpoint* getRoute(int part);
    void dispatch(Baggage* baggage);
    void dispatch(Baggage* baggage, ICheckpoint* checkpoint);
private:
    std::map<int, ICheckpoint*> routes_;
};


class XRay : public RouteCheckpoint {
public:
    XRay(ICheckpoint* contrabandBox) : contrabandBox_(contrabandBox) {}
    void checkIn(Baggage* baggage);
private:
    ICheckpoint* contrabandBox_;
};


class BaggageBox : public ICheckpoint, public ICollectable {
public:
    void checkIn(Baggage* baggage);
    void collect();
private:
    std::vector<Baggage*> content_;
};
