#include <iostream>
#include "Checkpoint.hpp"
#include "BaggageGen.hpp"
#include "Destination.hpp"
#include "Collector.hpp"

static const TDestinationAddress DEST_DEN = "DENMARK";
static const TDestinationAddress DEST_GER = "GERMANY";
static const TDestinationAddress DEST_GBR = "GREAT BRITAIN";
static const TDestinationAddress DEST_FRA = "FRANCE";
static const TDestinationAddress DEST_USA = "USA";
static const TDestinationAddress DEST_RHO = "RHODOS";
static const TDestinationAddress DEST_SPA = "SPAIN";
static const TDestinationAddress DEST_RUS = "RUSSIA";
static const TDestinationAddress DEST_SWE = "SWEDEN";


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

    Destination* dest1 = new Destination(DEST_DEN);
    Destination* dest2 = new Destination(DEST_FRA);
    Destination* dest3 = new Destination(DEST_GBR);
    Destination* dest4 = new Destination(DEST_GER);
    Destination* dest5 = new Destination(DEST_USA);
    Destination* dest6 = new Destination(DEST_RHO);

    Airplane *air1 = new Airplane(terminal1, dest1);
    Airplane *air2 = new Airplane(terminal2, dest2);
    Airplane *air3 = new Airplane(terminal3, dest3);
    Airplane *air4 = new Airplane(terminal4, dest4);
    Airplane *air5 = new Airplane(terminal5, dest5);
    Airplane *air6 = new Airplane(terminal6, dest6);

    BaggageGen bg(xray);
    bg.start();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
