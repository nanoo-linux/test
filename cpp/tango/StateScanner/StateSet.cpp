#include "StateSet.hpp"
#include "StateT2.hpp"

#include <cstdio>

StateSet::StateSet(pData d)
: State(d)
{}

void StateSet::do_target()
{
	data_->current_vvalue += vdelta;
	if (data_->current_vvalue > vstop) {
		finished = true;
	}
	dev_actuator->set_value(); //TODO:
}

pState StateSet::next_state()
{
	return pState(new StateT2(data()));
}
