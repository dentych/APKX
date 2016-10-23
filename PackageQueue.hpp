#pragma once

#include <queue>
#include <pthread.h>
#include <mutex>
#include <condition_variable>
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
    void push(int id, TPackage package = TPackage());
    TPackage pop(int &id);
private:
    std::queue<Item*> q_;
    std::mutex mtx_;
    std::condition_variable cond_;
};
