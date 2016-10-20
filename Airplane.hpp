#include <boost/statechart/transition.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/state.hpp>
#include "Checkpoint.hpp"
#include "Destination.hpp"

namespace sc = boost::statechart;

struct AtTerminal;
struct Delivering;

class Airplane : public sc::state_machine<Airplane, AtTerminal> {
public:
    Airplane(ICollectable *source, Destination *destination, unsigned int maxWeight);
    void onBaggageReady();
    void loadBaggage();
    void unloadBaggage();
    void connectSignal();
    void disconnectSignal();
    const ICheckpoint* getDestination();

    static Airplane* createAndInitiate(ICollectable *source, Destination *destination, unsigned int maxWeight);

private:
    ICollectable *source_;
    ICheckpoint *destination_;
    std::vector<std::shared_ptr<Package>> content_;
    boost::signals2::connection con;
    unsigned int maxWeight_;

    bool isFull();
    int getWeight();
};

struct EvFull : sc::event<EvFull> {
};

struct EvAtTerminal : sc::event<EvAtTerminal> {
};

struct AtTerminal : sc::state<AtTerminal, Airplane> {
    typedef sc::transition<EvFull, Delivering> reactions;

    AtTerminal(my_context ctx) : my_base(ctx) {
        context<Airplane>().connectSignal();
        context<Airplane>().loadBaggage();
    }
};

struct Delivering : sc::state<Delivering, Airplane> {
    typedef sc::transition<EvAtTerminal, AtTerminal> reactions;

    Delivering(my_context ctx) : my_base(ctx) {
        std::cout << "Airplane full - flying to " << context<Airplane>().getDestination()->getName() << std::endl;
        context<Airplane>().disconnectSignal();
        context<Airplane>().unloadBaggage();
        context<Airplane>().process_event(EvAtTerminal());
    }
};