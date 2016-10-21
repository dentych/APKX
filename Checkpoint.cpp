#include "Checkpoint.hpp"


// -- RouteCheckpoint --------------------------------------------------------


void RouteCheckpoint::checkIn(std::shared_ptr<Package> package) {
    dispatch(package);
};


void RouteCheckpoint::dispatch(std::shared_ptr<Package> package) {
    TDestinationAddress address = package->getDestination();
    if(hasRoute(address))
        dispatch(package, getRoute(address));
    else
        dispatch(package, nextCheckpoint_);
};


void RouteCheckpoint::dispatch(std::shared_ptr<Package> package, ICheckpoint* checkpoint) {
    checkpoint->checkIn(package);
};


void RouteCheckpoint::addRoute(TDestinationAddress address, ICheckpoint* checkpoint) {
    routes_[address] = checkpoint;
};

bool RouteCheckpoint::hasRoute(TDestinationAddress address) {
    return routes_.count(address) == 1;
}

ICheckpoint* RouteCheckpoint::getRoute(TDestinationAddress address) {
    return routes_[address];
};


// -- BaggageBox --------------------------------------------------------------


void BaggageBox::checkIn(std::shared_ptr<Package> package) {
    std::lock_guard<std::mutex> guard(contentMutex_);
    content_.push_back(package);
    std::cout << "Sending signal... " << signal_.num_slots() << std::endl;
    signal_();
}

TPackageVector& BaggageBox::getContent() {
    return content_;
}

std::string ICheckpoint::getName() const {
    return name_;
}
