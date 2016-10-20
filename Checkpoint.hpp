#pragma once

#include <map>
#include <vector>
#include <iostream>
#include <boost/signals2.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <mutex>
#include "Package.hpp"


typedef std::string TDestinationAddress;


class ICheckpoint {
public:
    virtual void checkIn(TPackage baggage) = 0;
};


class ICollectable {
    typedef boost::signals2::signal<void()> TSignal;
public:
    virtual std::vector<TPackage>::const_iterator collector() = 0;

    TSignal signal_;
protected:
    std::mutex contentMutex_;
};


class RouteCheckpoint : public ICheckpoint {
public:
    RouteCheckpoint(ICheckpoint *nextCheckpoint) : nextCheckpoint_(nextCheckpoint) {}

    void checkIn(TPackage baggage);

    void addRoute(TDestinationAddress address, ICheckpoint *checkpoint);

protected:
    ICheckpoint *getRoute(TDestinationAddress address);

    void dispatch(TPackage baggage);

    void dispatch(TPackage baggage, ICheckpoint *checkpoint);

    bool hasRoute(TDestinationAddress address);

private:
    std::map<TDestinationAddress, ICheckpoint *> routes_;
    ICheckpoint *nextCheckpoint_;
};



class BaggageBox : public ICheckpoint, public ICollectable {
public:
    BaggageBox() {}

    BaggageBox(std::string name) : name_(name) {}

    void checkIn(TPackage baggage);

    std::vector<TPackage>::const_iterator collector();

    std::mutex getLock();

private:
    std::vector<TPackage> content_;
    std::string name_;
};
