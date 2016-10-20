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

//static const std::string PackageFilePath = "packages.txt";
static const std::string PackageFilePath = "/home/dennis/Documents/git/APKX/packages.txt";

struct BaggageGeneratorThreadArgs {
    XRay* xray;
};


void* baggageGeneratorThread(void* data) {
    BaggageGeneratorThreadArgs* args = (BaggageGeneratorThreadArgs*) data;
    BaggageGen bg(args->xray, PackageFilePath);
    bg.start();
}


int main() {
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

    Airplane *air1 = Airplane::createAndInitiate(terminal1, dest1, 10000);
    Airplane *air2 = Airplane::createAndInitiate(terminal2, dest2, 10000);
    Airplane *air3 = Airplane::createAndInitiate(terminal3, dest3, 10000);
    Airplane *air4 = Airplane::createAndInitiate(terminal4, dest4, 10000);
    Airplane *air5 = Airplane::createAndInitiate(terminal5, dest5, 10000);
    Airplane *air6 = Airplane::createAndInitiate(terminal6, dest6, 10000);

    BaggageBox* contrabandBox = new BaggageBox("ContrabandBox");

    XRay *xray = new XRay(contrabandBox, checkpoint1);

    // Start package generator thread
    pthread_t generatorThread;
    BaggageGeneratorThreadArgs args;
    args.xray = xray;
    pthread_create(&generatorThread, NULL, baggageGeneratorThread, (void *) &args);

    // Let main thread process packages
    xray->process();

    delete dest1;
    delete dest2;
    delete dest3;
    delete dest4;
    delete dest5;
    delete dest6;

    return 0;
}
