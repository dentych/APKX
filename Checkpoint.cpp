#include "Checkpoint.hpp"


// -- RouteCheckpoint --------------------------------------------------------


void RouteCheckpoint::checkIn(Package* baggage) {
    dispatch(baggage);
};


void RouteCheckpoint::dispatch(Package* baggage) {
    dispatch(baggage, getRoute(baggage->nextPart()));
};


void RouteCheckpoint::dispatch(Package* baggage, ICheckpoint* checkpoint) {
    checkpoint->checkIn(baggage);
};


void RouteCheckpoint::addRoute(unsigned int part, ICheckpoint* checkpoint) {
    routes_[part] = checkpoint;
};


ICheckpoint* RouteCheckpoint::getRoute(unsigned int part) {
    return routes_[part];
};


// -- BaggageBox --------------------------------------------------------------


void BaggageBox::checkIn(Package* baggage) {
    content_.push_back(baggage);
};


void BaggageBox::collect() {

};
