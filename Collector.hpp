//
// Created by stud on 10/12/16.
//

#include "Checkpoint.hpp"
#include "Destination.hpp"


class Collector {
public:
    Collector(ICollectable *box) : box_(box) {}
    void collectBaggage();

protected:
    std::vector<Package*> content_;
    ICollectable* box_;
};

class Airplane : public Collector {
public:
    Airplane(ICollectable* box, Destination* destination);

    void operator()();
private:
    Destination* destination_;
};

class Police : public Collector {
    Police(ICollectable* box) : Collector(box) {}
};