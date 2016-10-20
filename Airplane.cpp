#include "Airplane.hpp"


Airplane::Airplane(ICollectable *source, Destination *destination, unsigned int maxWeight)
        : source_(source), destination_(destination), maxWeight_(maxWeight), loadedWeight_(0) {
    std::cout << "Connecting" << std::endl;
}


void Airplane::onBaggageReady() {
    std::cout << "Signal received!" << std::endl;
}


void Airplane::gotoDestination() {
    for (auto item : content_) {
        destination_->checkIn(item);
    }

    content_.clear();
}

void Airplane::connectSignal() {
    if (!con.connected())
        con = source_->signal_.connect(std::bind(&Airplane::onBaggageReady, this));
}

void Airplane::disconnectSignal() {
    if (con.connected())
        con.disconnect();
}

void Airplane::start() {

}

void Airplane::loadBaggage() {

}

void Airplane::unloadBaggage() {

}
