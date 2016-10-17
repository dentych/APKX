//
// Created by stud on 10/17/16.
//

#include "Collector.hpp"

void Collector::collectBaggage() {

    //collect baggage from and insert into vector - to be implemented
//    content_ = box_->collect();

}

Airplane::Airplane(ICollectable* box, Destination* destination) {
    box_ = box;
    destination_ = destination;
}

void Airplane::putBaggage() {

    for(int i = 0; i < content_.size(); i++) {
        destination_->arrivedBaggage.push_back(content_.at(i));
    }

    content_.clear();
}


Police::Police(ICollectable *box) {
    box_ = box;
}

