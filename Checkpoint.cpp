#include "Checkpoint.hpp"


// --RouteCheckpoint ---------------------------------------------------------


void RouteCheckpoint::checkIn(Baggage* bagage) {
    dispatch(bagage);
};


void RouteCheckpoint::dispatch(Baggage* bagage) {
    int part = bagage->nextPart();
    Checkpoint* checkpoint = getRoute(part);
    dispatch(bagage, checkpoint);
};


void RouteCheckpoint::dispatch(Baggage* bagage, Checkpoint* checkpoint) {
    checkpoint->checkIn(bagage);
};


void RouteCheckpoint::addRoute(int part, Checkpoint* checkpoint) {
    routes_[part] = checkpoint;
};


Checkpoint* RouteCheckpoint::getRoute(int part) {
    return routes_[part];
};


// -- XRay -------------------------------------------------------------------


XRay::XRay(Checkpoint* contrabandBox) {
    addRoute(contrabandPart_, contrabandBox);
}


void XRay::checkIn(Baggage* bagage) {
    bool isContraband = false;

    if(isContraband)
        dispatch(bagage, getRoute(contrabandPart_));
    else
        dispatch(bagage);
};


// -- BagageBox --------------------------------------------------------------


void BagageBox::checkIn(Baggage* bagage) {
    content_.push_back(bagage);
};


void BagageBox::empty() {

};
