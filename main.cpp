#include <iostream>
#include "Checkpoint.hpp"


ICheckpoint* setupCheckpointNetwork() {
    BaggageBox* terminal1 = new BaggageBox();
    BaggageBox* terminal2 = new BaggageBox();
    BaggageBox* terminal3 = new BaggageBox();
    BaggageBox* terminal4 = new BaggageBox();
    BaggageBox* terminal5 = new BaggageBox();
    BaggageBox* terminal6 = new BaggageBox();

    RouteCheckpoint* checkin = new RouteCheckpoint();
    BaggageBox* contrabandBox = new BaggageBox();
    XRay* xray = new XRay(contrabandBox);

    return checkin;
}


int main() {
    ICheckpoint* checkin = setupCheckpointNetwork();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
