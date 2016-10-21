#include <boost/statechart/transition.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/state.hpp>
#include "Checkpoint.hpp"

namespace sc = boost::statechart;

struct AtTerminal;
struct Delivering;

class Airplane : public sc::state_machine<Airplane, AtTerminal> {
public:
    Airplane(ICollectable *source, ICheckpoint *destination, unsigned int maxWeight);
    ~Airplane();
    void onBaggageReady();
    void loadBaggage();
    void unloadBaggage();
    void connectSignal();
    void disconnectSignal();
    const ICheckpoint* getDestination();

    static Airplane* createAndInitiate(ICollectable *source, ICheckpoint *destination, unsigned int maxWeight);

private:
    ICollectable *source_;
    ICheckpoint *destination_;
    std::vector<std::shared_ptr<Package>> content_;
    boost::signals2::scoped_connection con;
    unsigned int maxWeight_;

    bool isFull();
    int getWeight();
};

struct EvFull : sc::event<EvFull> {
};

struct EvAtTerminal : sc::event<EvAtTerminal> {
};

struct AtTerminal : sc::state<AtTerminal, Airplane> {
    typedef sc::state<AtTerminal, Airplane> base;
    typedef sc::transition<EvFull, Delivering> reactions;

    AtTerminal(my_context ctx) : base(ctx) {
        std::cout << "Airplane to " << context<Airplane>().getDestination()->getName() << " at Terminal" << std::endl;
        context<Airplane>().connectSignal();
        context<Airplane>().loadBaggage();
    }
};

struct Delivering : sc::state<Delivering, Airplane> {
    typedef sc::state<Delivering, Airplane> base;
    typedef sc::transition<EvAtTerminal, AtTerminal> reactions;

    Delivering(my_context ctx) : base(ctx) {
        std::cout << "Airplane full - flying to " << context<Airplane>().getDestination()->getName() << std::endl;
        context<Airplane>().disconnectSignal();
        context<Airplane>().unloadBaggage();
    }
};