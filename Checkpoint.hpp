#pragma once
#include "Bagage.hpp"


class Checkpoint {
public:
    virtual checkIn(Bagage* bagage, int ttl) = 0;
};


class BagageBox : Checkpoint {
public:
    checkIn(Bagage* bagage, int ttl);
};


class RouteCheckpoint : Checkpoint {
public:
    checkIn(Bagage* bagage, int ttl);
};
