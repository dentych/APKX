#include <iostream>
#include "PackageQueue.hpp"


void PackageQueue::push(int id, TPackage package) {
    std::unique_lock<std::mutex> lock(mtx_);

    q_.push(new Item(id, package));

    cond_.notify_all();
}


TPackage PackageQueue::pop(int &id) {
    std::unique_lock<std::mutex> lock(mtx_);

    cond_.wait(lock, [&]{ return q_.size() > 0; });

    Item *item = q_.front();
    q_.pop();


    id = item->id;
    TPackage package = item->package;
    delete item;

    return package;
}
