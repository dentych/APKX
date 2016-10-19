#include "Checkpoint.hpp"


// -- RouteCheckpoint --------------------------------------------------------


void RouteCheckpoint::checkIn(Package* baggage) {
    dispatch(baggage);
};


void RouteCheckpoint::dispatch(Package* baggage) {
    TDestinationAddress address = baggage->getDestination();
    if(hasRoute(address))
        dispatch(baggage, getRoute(address));
    else
        dispatch(baggage, nextCheckpoint_);
};


void RouteCheckpoint::dispatch(Package* baggage, ICheckpoint* checkpoint) {
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


void BaggageBox::checkIn(Package *baggage) {
    std::cout << "BaggageBox received: " << baggage->getDestination() << std::endl;
    content_.push_back(baggage);
};


void BaggageBox::collect() {

};
