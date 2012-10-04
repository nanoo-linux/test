#include "StateT2.hpp"
#include "StateMes.hpp"

using namespace std;

StateT2::StateT2(pData d)
: State(d)
{}

void StateT2::do_target()
{
	this_thread::sleep_for(chrono::milliseconds(data_->delta1));
}

pState StateT2::next_state()
{
	return pState(new StateMes(data()));
}
