//
// Created by dennis on 12/10/16.
//

#ifndef APKX_BAGAGE_H
#define APKX_BAGAGE_H

#include <string>
#include <vector>

#define ARR_SIZE 4

class Bagage {
public:
    Bagage() = delete;

    void setDestination(int destination[]) {
        std::copy(std::begin(destination), std::end(destination), std::begin(this->destination));
    }

    int nextDestination() {
        if (counter < 0 || counter > ARR_SIZE - 1) {
            return 0;
        }
        int value = destination[counter];
        counter++;
        return value;
    }

protected:
    int destination[ARR_SIZE];
    int counter;
};

#endif //APKX_BAGAGE_H
