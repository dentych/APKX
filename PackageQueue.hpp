#pragma once

#include <queue>
#include <pthread.h>
#include "Package.hpp"


struct Item {
    Item(TPackage p) : package(p) {};
    TPackage package;
};


class PackageQueue
{
public:
    PackageQueue();
    ~PackageQueue();
    void push(TPackage package);
    TPackage pop();
private:
    std::queue<Item*> q_;
    pthread_mutex_t mtx_;
    pthread_cond_t cond_;
};
