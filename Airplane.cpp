#include "Airplane.hpp"


Airplane::Airplane(ICollectable *source, Destination *destination, unsigned int maxWeight)
        : source_(source), destination_(destination), maxWeight_(maxWeight) {
    std::cout << "Connecting" << std::endl;
}


void Airplane::onBaggageReady() {
    std::cout << "Signal received!" << std::endl;
    loadBaggage();
}


void Airplane::connectSignal() {
    if (!con.connected())
        con = source_->signal_.connect(std::bind(&Airplane::onBaggageReady, this));
}

void Airplane::disconnectSignal() {
    if (con.connected())
        con.disconnect();
}

void Airplane::loadBaggage() {
    TPackageVector boxContent = source_->getContent();

    for (auto iter = boxContent.begin(); iter != boxContent.end();) {
        content_.push_back(*iter);
        iter = boxContent.erase(iter);

        if (isFull()) {
            process_event(EvFull());
            break;
        }
    }
}

void Airplane::unloadBaggage() {
    for (auto iter : content_) {
        destination_->checkIn(iter);
    }
}

Airplane *Airplane::createAndInitiate(ICollectable *source, Destination *destination, unsigned int maxWeight) {
    Airplane* airplane = new Airplane(source, destination, maxWeight);
    airplane->initiate();
    return airplane;
}

bool Airplane::isFull() {
    int weight = getWeight();
    return (weight >= maxWeight_);
}

const ICheckpoint* Airplane::getDestination() {
    return destination_;
}

int Airplane::getWeight() {
    int weight = 0;
    for (auto iter : content_) {
        weight += iter->getWeight();
    }
    return weight;
}
