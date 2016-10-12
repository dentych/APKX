#include "Checkpoint.hpp"


// --RouteCheckpoint ---------------------------------------------------------


void RouteCheckpoint::checkIn(Bagage* bagage) {
    dispatch(bagage);
};


void RouteCheckpoint::dispatch(Bagage* bagage) {
    int part = bagage->nextPart();
    Checkpoint* checkpoint = getRoute(part);
    checkpoint->checkIn(bagage);
};


void RouteCheckpoint::addRoute(int part, Checkpoint* checkpoint) {
    routes[part] = checkpoint;
};


int RouteCheckpoint::getRoute(int part) {
    return routes[part];
};


// -- XRay -------------------------------------------------------------------


XRay::XRay(Checkpoint* contrabandBox) {
    addRoute(contrabandPart_, contrabandBox);
}


void XRay::checkIn(Bagage* bagage) {
    dispatch(bagage);
};


// -- BagageBox --------------------------------------------------------------


void BagageBox::checkIn(Bagage* bagage) {
    
};


void BagageBox::empty() {

};
