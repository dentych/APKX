#include "Airplane.hpp"


Airplane::Airplane(ICollectable *source, ICheckpoint *destination, unsigned int maxWeight)
        : source_(source), destination_(destination), maxWeight_(maxWeight) {
    initiate();
}


void Airplane::onPackageReady() {
    loadPackages();
}


void Airplane::connectSignal() {
    if (!con.connected())
        con = source_->signal.connect(std::bind(&Airplane::onPackageReady, this));
}

void Airplane::disconnectSignal() {
    if (con.connected())
        con.disconnect();
}

void Airplane::loadPackages() {
    TPackageVector& boxContent = source_->getContent();

    for (auto iter = boxContent.begin(); iter != boxContent.end();) {
        content_.push_back(*iter);
        iter = boxContent.erase(iter);

        if (isFull()) {
            process_event(EvFull());
            process_event(EvAtTerminal());
            break;
        }
    }
}

void Airplane::unloadPackages() {
    for (auto iter : content_) {
        destination_->checkIn(iter);
    }

    content_.clear();
}

Airplane *Airplane::createAndInitiate(ICollectable *source, ICheckpoint *destination, unsigned int maxWeight) {
    Airplane* airplane = new Airplane(source, destination, maxWeight);
    airplane->initiate();
    return airplane;
}

Airplane::~Airplane() {
    process_event(EvFull());
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
