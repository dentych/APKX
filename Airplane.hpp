#include <boost/statechart/transition.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include "Checkpoint.hpp"
#include "Destination.hpp"

namespace sc = boost::statechart;

struct InitialState;

class Airplane : public sc::state_machine<Airplane, InitialState> {
public:
    Airplane(ICollectable *source, Destination *destination, unsigned int maxWeight);

    void start();

    void onBaggageReady();

    void loadBaggage();

    void unloadBaggage();

private:
    ICollectable *source_;
    ICheckpoint *destination_;
    std::vector<std::shared_ptr<Package>> content_;

    unsigned int maxWeight_;
    unsigned int loadedWeight_;

    void gotoDestination();
};

struct EvFull : sc::event<EvFull> {
};

struct InitialState : sc::simple_state<InitialState, Airplane> {
    typedef sc::transition<EvFull, InitialState> reactions;
};