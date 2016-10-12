#pragma once

#include <map>
#include <vector>
#include "Bagage.hpp"


class ICheckpoint {
public:
    virtual void checkIn(Bagage* bagage) = 0;
};


class ICollectable {
public:
    virtual void collect() = 0;
};


class RouteCheckpoint : public ICheckpoint {
public:
    void checkIn(Bagage* bagage);
    void addRoute(int part, ICheckpoint* checkpoint);
protected:
    ICheckpoint* getRoute(int part);
    void dispatch(Bagage* bagage);
    void dispatch(Bagage* bagage, ICheckpoint* checkpoint);
private:
    std::map<int, ICheckpoint*> routes_;
};


class XRay : public RouteCheckpoint {
public:
    XRay(ICheckpoint* contrabandBox) : contrabandBox_(contrabandBox) {}
    void checkIn(Bagage* bagage);
private:
    ICheckpoint* contrabandBox_;
};


class BagageBox : public ICheckpoint, public ICollectable {
public:
    void checkIn(Bagage* bagage);
    void collect();
private:
    std::vector<Bagage*> content_;
};
