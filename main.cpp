#include <iostream>
#include <pthread.h>
#include <thread>
#include "Checkpoint.hpp"
#include "PackageGen.hpp"
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

struct PackageGeneratorThreadArgs {
    XRay* xray;
};


void* packageGeneratorThread(XRay* args) {
    PackageGen bg(args, PackageFilePath);
    bg.start();
}


int main() {
    PackageBox trashCan("Trash");

    PackageBox terminal1("Terminal 1");
    PackageBox terminal2("Terminal 2");
    PackageBox terminal3("Terminal 3");
    PackageBox terminal4("Terminal 4");
    PackageBox terminal5("Terminal 5");
    PackageBox terminal6("Terminal 6");

    RouteCheckpoint checkpoint2(&trashCan);
    checkpoint2.addRoute(DEST_DEN, &terminal1);
    checkpoint2.addRoute(DEST_FRA, &terminal2);
    checkpoint2.addRoute(DEST_GBR, &terminal3);

    RouteCheckpoint checkpoint1(checkpoint2);
    checkpoint1.addRoute(DEST_GER, &terminal4);
    checkpoint1.addRoute(DEST_USA, &terminal5);
    checkpoint1.addRoute(DEST_RHO, &terminal6);

    Destination dest1(DEST_DEN);
    Destination dest2(DEST_FRA);
    Destination dest3(DEST_GBR);
    Destination dest4(DEST_GER);
    Destination dest5(DEST_USA);
    Destination dest6(DEST_RHO);

    Airplane air1(&terminal1, &dest1, 200);
    Airplane air2(&terminal2, &dest2, 200);
    Airplane air3(&terminal3, &dest3, 200);
    Airplane air4(&terminal4, &dest4, 200);
    Airplane air5(&terminal5, &dest5, 200);
    Airplane air6(&terminal6, &dest6, 200);

    PackageBox* contrabandBox = new PackageBox("ContrabandBox");

    XRay *xray = new XRay(contrabandBox, &checkpoint1);

    // Start package generator thread
    std::thread generatorThread(packageGeneratorThread, xray);

    // Let main thread process packages
    xray->process();

    generatorThread.join();

    return 0;
}
