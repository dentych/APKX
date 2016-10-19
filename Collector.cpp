//
// Created by stud on 10/17/16.
//

#include "Collector.hpp"

void Collector::collectBaggage() {

    //collect baggage from and insert into vector - to be implemented
//    content_ = box_->collect();

}

Airplane::Airplane(ICollectable *box, Destination *destination) : Collector(box), destination_(destination) {
    std::cout << "Connecting" << std::endl;
    box_->signal.connect(*this);
}

void Airplane::operator()() {
    std::cout << "Signal received!" << std::endl;
}
