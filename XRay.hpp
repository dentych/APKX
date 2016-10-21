#pragma once

#include "meta.hpp"
#include "PackageQueue.hpp"
#include "Checkpoint.hpp"


class XRay {
public:
    XRay(ICheckpoint *contrabandBox, ICheckpoint *checkpoint)
            : contrabandBox_(contrabandBox), checkpoint_(checkpoint) {}

template<typename T>
void checkIn(std::shared_ptr<T> package) {
    if (contains<ContrabandTypes, T>::value)
        contrabandBox_->checkIn(package);
    else
        queue_.push(E_PACKAGE, package);
}

    void stop() {
        queue_.push(E_STOP);
    }

    void process() {
        while (1) {
            int id;
            TPackage package = queue_.pop(id);
            if (id == E_STOP)
                break;

            checkpoint_->checkIn(package);
        }
    }

private:
    PackageQueue queue_;
    ICheckpoint *contrabandBox_;
    ICheckpoint *checkpoint_;
};
