#include "PackageQueue.hpp"


PackageQueue::PackageQueue() {
    pthread_mutex_init(&mtx_, NULL);
    pthread_cond_init(&cond_, NULL);
}


PackageQueue::~PackageQueue() {
    pthread_mutex_destroy(&mtx_);
    pthread_cond_destroy(&cond_);
}


void PackageQueue::push(int id, TPackage package) {
    pthread_mutex_lock(&mtx_);
    
    q_.push(new Item(id, package));
    
    pthread_mutex_unlock(&mtx_);
    pthread_cond_signal(&cond_);
}


TPackage PackageQueue::pop(int &id) {
    pthread_mutex_lock(&mtx_);
    
    while (q_.size() < 1)
        pthread_cond_wait(&cond_, &mtx_);
    
    Item* item = q_.front();
    q_.pop();
    
    pthread_mutex_unlock(&mtx_);

    id = item->id;
    TPackage package = item->package;
    delete item;
    
    return package;
}
