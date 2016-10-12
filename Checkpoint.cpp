#include "Checkpoint.hpp"


// -- RouteCheckpoint --------------------------------------------------------


void RouteCheckpoint::checkIn(Baggage* baggage) {
    dispatch(baggage);
};


void RouteCheckpoint::dispatch(Baggage* baggage) {
    dispatch(baggage, getRoute(baggage->nextPart()));
};


void RouteCheckpoint::dispatch(Baggage* baggage, ICheckpoint* checkpoint) {
    checkpoint->checkIn(baggage);
};


void RouteCheckpoint::addRoute(int part, ICheckpoint* checkpoint) {
    routes_[part] = checkpoint;
};


ICheckpoint* RouteCheckpoint::getRoute(int part) {
    return routes_[part];
};


// -- XRay -------------------------------------------------------------------


template<typename T>
void XRay::checkIn(T baggage) {
    bool isContraband = false;

    if(contains<ContrabandTypes, T>::value)
        dispatch(baggage, contrabandBox_);
    else
        dispatch(baggage);
};


// -- BaggageBox --------------------------------------------------------------


void BaggageBox::checkIn(Baggage* baggage) {
    content_.push_back(baggage);
};


void BaggageBox::collect() {

};
