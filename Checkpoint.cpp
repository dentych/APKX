#include "Checkpoint.hpp"


// -- RouteCheckpoint --------------------------------------------------------


void RouteCheckpoint::checkIn(Bagage* bagage) {
    dispatch(bagage);
};


void RouteCheckpoint::dispatch(Bagage* bagage) {
    dispatch(bagage, getRoute(bagage->nextPart()));
};


void RouteCheckpoint::dispatch(Bagage* bagage, ICheckpoint* checkpoint) {
    checkpoint->checkIn(bagage);
};


void RouteCheckpoint::addRoute(int part, ICheckpoint* checkpoint) {
    routes_[part] = checkpoint;
};


ICheckpoint* RouteCheckpoint::getRoute(int part) {
    return routes_[part];
};


// -- XRay -------------------------------------------------------------------


void XRay::checkIn(Bagage* bagage) {
    bool isContraband = false;

    if(isContraband)
        dispatch(bagage, contrabandBox_);
    else
        dispatch(bagage);
};


// -- BagageBox --------------------------------------------------------------


void BagageBox::checkIn(Bagage* bagage) {
    content_.push_back(bagage);
};


void BagageBox::collect() {

};
