#include <iostream>
#include "Checkpoint.hpp"
#include "BaggageGen.hpp"

static const TDestinationAddress DEST_DEN = "DEN";
static const TDestinationAddress DEST_GER = "GER";
static const TDestinationAddress DEST_GBR = "GBR";
static const TDestinationAddress DEST_FRA = "FRA";
static const TDestinationAddress DEST_USA = "USA";
static const TDestinationAddress DEST_RHO = "RHO";


int main() {
    BaggageBox* trashCan = new BaggageBox();

    BaggageBox* terminal1 = new BaggageBox();
    BaggageBox* terminal2 = new BaggageBox();
    BaggageBox* terminal3 = new BaggageBox();
    BaggageBox* terminal4 = new BaggageBox();
    BaggageBox* terminal5 = new BaggageBox();
    BaggageBox* terminal6 = new BaggageBox();

    RouteCheckpoint* checkpoint2 = new RouteCheckpoint(trashCan);
    checkpoint2->addRoute(DEST_DEN, terminal1);
    checkpoint2->addRoute(DEST_FRA, terminal2);
    checkpoint2->addRoute(DEST_GBR, terminal3);

    RouteCheckpoint* checkpoint1 = new RouteCheckpoint(checkpoint2);
    checkpoint2->addRoute(DEST_GER, terminal4);
    checkpoint2->addRoute(DEST_USA, terminal5);
    checkpoint2->addRoute(DEST_RHO, terminal6);

    BaggageBox* contrabandBox = new BaggageBox();

    XRay* xray = new XRay(contrabandBox, checkpoint1);

    BaggageGen bg(xray);
    bg.start();


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
