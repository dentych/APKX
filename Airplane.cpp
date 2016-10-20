#include "Airplane.hpp"


void Airplane::Airplane(ICollectable *source, Destination *destination, unsigned int maxWeight) {
}


void Collector::loadBaggage() {
    //collect baggage from and insert into vector - to be implemented
    std::vector<std::shared_ptr<Package>> itemsCollected = box_->collect();
    for (auto item : itemsCollected) {
        content_.push_back(item);
    }
}


Airplane::Airplane(ICollectable *box, Destination *destination, unsigned int maxWeight)
        : Collector(box), destination_(destination), maxWeight_(maxWeight), weight_(0) {
    std::cout << "Connecting" << std::endl;
    con = box_->signal_.connect(std::bind(&Collector::leCallback, this));
    std::cout << "Num slots: " << box_->signal_.num_slots() << std::endl;
}


void Airplane::collectBaggage() {
    std::vector<std::shared_ptr<Package>> itemsCollected = box_->collect();
    unsigned int weightOfCollectedItems = 0;
    for (auto item : itemsCollected) {
        weightOfCollectedItems += item->getWeight();
        content_.push_back(item);
    }

    weight_ += weightOfCollectedItems;

    if (weight_ >= maxWeight_) {
        gotoDestination();
    }
}


void Airplane::operator()() {
    std::cout << "Signal received!" << std::endl;
}


void Airplane::gotoDestination() {
    for (auto item : content_) {
        destination_->checkIn(item);
    }

    content_.clear();
}


void Airplane::leCallback() {
    std::cout << "Signal received!" << std::endl;
}
