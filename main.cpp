#include <iostream>
#include "Checkpoint.hpp"


ICheckpoint* setupCheckpointNetwork() {
    BagageBox* terminal1 = new BagageBox();
    BagageBox* terminal2 = new BagageBox();
    BagageBox* terminal3 = new BagageBox();
    BagageBox* terminal4 = new BagageBox();
    BagageBox* terminal5 = new BagageBox();
    BagageBox* terminal6 = new BagageBox();

    RouteCheckpoint* checkin = new RouteCheckpoint();
    BagageBox* contrabandBox = new BagageBox();
    XRay* xray = new XRay(contrabandBox);

    return checkin;
}


int main() {
    ICheckpoint* checkin = setupCheckpointNetwork();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
