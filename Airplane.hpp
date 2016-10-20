#include <boost/statechart/transition.hpp>
#include "Checkpoint.hpp"
#include "Destination.hpp"


class Airplane {
public:
    Airplane(ICollectable *source, Destination *destination, unsigned int maxWeight);
    void start();
    void onBaggageReady();
    void loadBaggage();
    void unloadBaggage();
private:
    ICollectable* source_;
    ICheckpoint* destination_;
    std::vector<std::shared_ptr<Package>> content_;

    unsigned int maxWeight_;
    unsigned int loadedWeight_;

    void gotoDestination();
};
