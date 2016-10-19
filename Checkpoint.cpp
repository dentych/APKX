#include "Checkpoint.hpp"


// -- RouteCheckpoint --------------------------------------------------------


void RouteCheckpoint::checkIn(std::shared_ptr<Package> baggage) {
    dispatch(baggage);
};


void RouteCheckpoint::dispatch(std::shared_ptr<Package> baggage) {
    TDestinationAddress address = baggage->getDestination();
    if(hasRoute(address))
        dispatch(baggage, getRoute(address));
    else
        dispatch(baggage, nextCheckpoint_);
};


void RouteCheckpoint::dispatch(std::shared_ptr<Package> baggage, ICheckpoint* checkpoint) {
    checkpoint->checkIn(baggage);
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


void BaggageBox::checkIn(std::shared_ptr<Package> baggage) {
    std::string name = name_.length() > 0 ? name_ : "BaggageBox";
    std::cout << name << " received: " << baggage->getDestination() << std::endl;
    content_.push_back(baggage);
    std::cout << "Sending signal... " << signal_.num_slots() << std::endl;
    ICollectable::signal_();
}

std::vector<std::shared_ptr<Package>> BaggageBox::collect() {
    std::vector<std::shared_ptr<Package>> itemsToMove(content_);
    content_.clear();
    return itemsToMove;
};
