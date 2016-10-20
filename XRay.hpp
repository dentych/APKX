#pragma once

#include "meta.hpp"
#include "PackageQueue.hpp"
#include "Checkpoint.hpp"


class XRay {
public:
    XRay(ICheckpoint *contrabandBox, ICheckpoint *checkpoint)
            : contrabandBox_(contrabandBox), checkpoint_(checkpoint) {}

    template<typename T>
    void checkIn(std::shared_ptr<T> baggage) {
        if (contains<ContrabandTypes, T>::value)
            contrabandBox_->checkIn(baggage);
        else
            queue_.push(baggage);
    }

    void process() {
        while(1)
            checkpoint_->checkIn(queue_.pop());
    }

private:
    PackageQueue queue_;
    ICheckpoint* contrabandBox_;
    ICheckpoint* checkpoint_;
};
