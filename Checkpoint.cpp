#include "Checkpoint.hpp"


// --RouteCheckpoint ---------------------------------------------------------


void RouteCheckpoint::checkIn(Bagage* bagage) {
    dispatch(bagage);
};


void RouteCheckpoint::dispatch(Bagage* bagage) {
    int part = bagage->nextPart();
    Checkpoint* checkpoint = getRoute(part);
    dispatch(bagage, checkpoint);
};


void RouteCheckpoint::dispatch(Bagage* bagage, Checkpoint* checkpoint) {
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


void XRay::checkIn(Bagage* bagage) {
    bool isContraband = false;

    if(isContraband)
        dispatch(bagage, getRoute(contrabandPart_));
    else
        dispatch(bagage);
};


// -- BagageBox --------------------------------------------------------------


void BagageBox::checkIn(Bagage* bagage) {
    content_.push_back(bagage);
};


void BagageBox::empty() {

};
