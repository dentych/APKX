#pragma once

#include <queue>
#include <pthread.h>
#include "Package.hpp"

enum ItemType {
    E_PACKAGE,
    E_STOP
};

struct Item {
    Item(int id, TPackage p) : id(id), package(p) {};
    int id;
    TPackage package;
};


class PackageQueue
{
public:
    PackageQueue();
    ~PackageQueue();
    void push(int id, TPackage package = TPackage());
    TPackage pop(int &id);
private:
    std::queue<Item*> q_;
    pthread_mutex_t mtx_;
    pthread_cond_t cond_;
};
