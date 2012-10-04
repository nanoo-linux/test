#include "StateT1.hpp"
#include "StateSet.hpp"

using namespace std;

StateT1::StateT1(pData d)
: State(d)
{}

void StateT1::do_target()
{
	this_thread::sleep_for(chrono::milliseconds(data_->delta1));
}

pState StateT1::next_state()
{
	return pState(new StateSet(data()));
}
