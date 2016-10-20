#include "Airplane.hpp"


void Airplane::loadBaggage() {
    //collect baggage from and insert into vector - to be implemented
//    std::vector<std::shared_ptr<Package>> itemsCollected = source_->collector();
//    for (auto item : itemsCollected) {
//        content_.push_back(item);
//    }
}


Airplane::Airplane(ICollectable *source, Destination *destination, unsigned int maxWeight)
        : source_(source), destination_(destination), maxWeight_(maxWeight), loadedWeight_(0) {
    std::cout << "Connecting" << std::endl;
    source_->signal_.connect(std::bind(&Airplane::onBaggageReady, std::ref(*this)));
    std::cout << "Num slots: " << source_->signal_.num_slots() << std::endl;
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
