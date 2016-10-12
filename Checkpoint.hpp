#pragma once

#include <map>
#include "Bagage.hpp"


class Checkpoint {
public:
    virtual checkIn(Bagage* bagage) = 0;
};


class RouteCheckpoint : public Checkpoint {
public:
    void checkIn(Bagage* bagage);
    void addRoute(int part, Checkpoint* checkpoint);
protected:
    Checkpoint* getRoute(int part);
    void dispatch(Bagage* bagage);
    void dispatchTo(Bagage* bagage, Checkpoint* checkpoint);
private:
    std::map<int, Checkpoint*> routes_;
};


class XRay : public RouteCheckpoint {
private:
    static const int contrabandPart_ = -1;
public:
    public XRay(Checkpoint* contrabandBox);
    checkIn(Bagage* bagage);
};


class BagageBox : public Checkpoint {
public:
    checkIn(Bagage* bagage);
    void empty();
};
