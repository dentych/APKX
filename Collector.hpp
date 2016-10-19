//
// Created by stud on 10/12/16.
//

#include "Checkpoint.hpp"
#include "Destination.hpp"

class Collector {
public:
    Collector(ICollectable *box) : box_(box) {}
    virtual void collectBaggage();
    virtual void leCallback() = 0;
    virtual void operator()() = 0;
protected:
    std::vector<std::shared_ptr<Package>> content_;
    ICollectable* box_;
    boost::signals2::connection con;
};

class Airplane : public Collector {
public:
    Airplane(ICollectable *box, Destination *destination, unsigned int maxWeight);

    void collectBaggage();

    void operator()();

    void leCallback();
private:
    Destination* destination_;
    unsigned int maxWeight_;
    unsigned int weight_;

    void gotoDestination();
};

class Police : public Collector {
    Police(BaggageBox* box) : Collector(box) {}
};