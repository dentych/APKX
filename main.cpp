#include <iostream>
#include <pthread.h>
#include "Checkpoint.hpp"
#include "BaggageGen.hpp"
#include "Destination.hpp"
#include "Airplane.hpp"

static const TDestinationAddress DEST_DEN = "DEN";
static const TDestinationAddress DEST_GER = "GER";
static const TDestinationAddress DEST_GBR = "GBR";
static const TDestinationAddress DEST_FRA = "FRA";
static const TDestinationAddress DEST_USA = "USA";
static const TDestinationAddress DEST_RHO = "RHO";
static const TDestinationAddress DEST_SPA = "SPA";
static const TDestinationAddress DEST_RUS = "RUS";
static const TDestinationAddress DEST_SWE = "SWE";

static const std::string PackageFilePath = "packages.txt";


struct BaggageGeneratorThreadArgs {
    XRay* xray;
};


void* baggageGeneratorThread(void* data) {
    BaggageGeneratorThreadArgs* args = (BaggageGeneratorThreadArgs*) data;
    BaggageGen bg(args->xray, PackageFilePath);
    bg.start();
}


XRay* createInfrastructure() {
    BaggageBox* trashCan = new BaggageBox("Trash");

    BaggageBox* terminal1 = new BaggageBox("Terminal 1");
    BaggageBox* terminal2 = new BaggageBox("Terminal 2");
    BaggageBox* terminal3 = new BaggageBox("Terminal 3");
    BaggageBox* terminal4 = new BaggageBox("Terminal 4");
    BaggageBox* terminal5 = new BaggageBox("Terminal 5");
    BaggageBox* terminal6 = new BaggageBox("Terminal 6");

    RouteCheckpoint* checkpoint2 = new RouteCheckpoint(trashCan);
    checkpoint2->addRoute(DEST_DEN, terminal1);
    checkpoint2->addRoute(DEST_FRA, terminal2);
    checkpoint2->addRoute(DEST_GBR, terminal3);

    RouteCheckpoint* checkpoint1 = new RouteCheckpoint(checkpoint2);
    checkpoint1->addRoute(DEST_GER, terminal4);
    checkpoint1->addRoute(DEST_USA, terminal5);
    checkpoint1->addRoute(DEST_RHO, terminal6);

    Destination* dest1 = new Destination(DEST_DEN);
    Destination* dest2 = new Destination(DEST_FRA);
    Destination* dest3 = new Destination(DEST_GBR);
    Destination* dest4 = new Destination(DEST_GER);
    Destination* dest5 = new Destination(DEST_USA);
    Destination* dest6 = new Destination(DEST_RHO);

    Airplane *air1 = new Airplane(terminal1, dest1, 100);
    Airplane *air2 = new Airplane(terminal2, dest2, 100);
    Airplane *air3 = new Airplane(terminal3, dest3, 100);
    Airplane *air4 = new Airplane(terminal4, dest4, 100);
    Airplane *air5 = new Airplane(terminal5, dest5, 100);
    Airplane *air6 = new Airplane(terminal6, dest6, 100);

    BaggageBox* contrabandBox = new BaggageBox("ContrabandBox");

    return new XRay(contrabandBox, checkpoint1);
}


int main() {
    XRay* xray = createInfrastructure();

    // Start package generator thread
    pthread_t generatorThread;
    BaggageGeneratorThreadArgs args;
    args.xray = xray;
    pthread_create(&generatorThread, NULL, baggageGeneratorThread, (void*) &args);

    // Let main thread process packages
    xray->process();

    return 0;
}
