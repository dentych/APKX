#include "Checkpoint.hpp"


// -- RouteCheckpoint --------------------------------------------------------


<<<<<<< HEAD
void RouteCheckpoint::checkIn(Baggage* baggage) {
    dispatch(baggage);
};


void RouteCheckpoint::dispatch(Baggage* baggage) {
    dispatch(baggage, getRoute(baggage->nextPart()));
};


void RouteCheckpoint::dispatch(Baggage* baggage, ICheckpoint* checkpoint) {
    checkpoint->checkIn(baggage);
=======
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
>>>>>>> 0804d1843da082291eec7f7950aa2fa0f9f51384
};


void RouteCheckpoint::addRoute(int part, ICheckpoint* checkpoint) {
    routes_[part] = checkpoint;
};


ICheckpoint* RouteCheckpoint::getRoute(int part) {
    return routes_[part];
};


// -- XRay -------------------------------------------------------------------


<<<<<<< HEAD
void XRay::checkIn(Baggage* baggage) {
=======
XRay::XRay(Checkpoint* contrabandBox) {
    addRoute(contrabandPart_, contrabandBox);
}


void XRay::checkIn(Baggage* bagage) {
>>>>>>> 0804d1843da082291eec7f7950aa2fa0f9f51384
    bool isContraband = false;

    if(isContraband)
        dispatch(baggage, contrabandBox_);
    else
        dispatch(baggage);
};


// -- BaggageBox --------------------------------------------------------------


<<<<<<< HEAD
void BaggageBox::checkIn(Baggage* baggage) {
    content_.push_back(baggage);
=======
void BagageBox::checkIn(Baggage* bagage) {
    content_.push_back(bagage);
>>>>>>> 0804d1843da082291eec7f7950aa2fa0f9f51384
};


void BaggageBox::collect() {

};
