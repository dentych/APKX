#include "PackageQueue.hpp"


PackageQueue::PackageQueue() {
    pthread_mutex_init(&mtx_, NULL);
    pthread_cond_init(&cond_, NULL);
}


PackageQueue::~PackageQueue() {
    pthread_mutex_destroy(&mtx_);
    pthread_cond_destroy(&cond_);
}


void PackageQueue::push(TPackage package) {
    pthread_mutex_lock(&mtx_);
    
    q_.push(new Item(package));
    
    pthread_mutex_unlock(&mtx_);
    pthread_cond_signal(&cond_);
}


TPackage PackageQueue::pop() {
    pthread_mutex_lock(&mtx_);
    
    while (q_.size() < 1)
        pthread_cond_wait(&cond_, &mtx_);
    
    Item* item = q_.front();
    q_.pop();
    
    pthread_mutex_unlock(&mtx_);
    
    TPackage package = item->package;
    delete item;
    
    return package;
}
