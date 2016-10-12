//
// Created by dennis on 12/10/16.
//

#ifndef APKX_BAGAGE_H
#define APKX_BAGAGE_H

#include <string>
#include <vector>

class Bagage {
public:
    virtual void setDestination(int destination[]) = 0;
    virtual int nextDestination(int level) = 0;
protected:
    int destination[4];
};

#endif //APKX_BAGAGE_H
