#pragma once

#include <map>
#include "Baggage.hpp"


class Checkpoint {
public:
    virtual void checkIn(Baggage* bagage) = 0;
};


class RouteCheckpoint : public Checkpoint {
public:
    void checkIn(Baggage* bagage);
    void addRoute(int part, Checkpoint* checkpoint);
protected:
    Checkpoint* getRoute(int part);
    void dispatch(Baggage* bagage);
    void dispatch(Baggage* bagage, Checkpoint* checkpoint);
private:
    std::map<int, Checkpoint*> routes_;
};


class XRay : public RouteCheckpoint {
private:
    static const int contrabandPart_ = -1;
public:
    XRay(Checkpoint* contrabandBox);
    void checkIn(Baggage* bagage);
};


class BagageBox : public Checkpoint {
private:
    std::vector<Baggage*> content_;
public:
    void checkIn(Baggage* bagage);
    void empty();
};
