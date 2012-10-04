#include "StateMes.hpp"
#include "StateT1.hpp"

#include <cstdio>

StateMes::StateMes(pData d)
: State(d)
{}

void StateMes::do_target()
{
	double value = dev_sensor->get_value() //TODO:
	spectrum.push_back(value);
}

pState StateMes::next_state()
{
	return pState(new StateT1(data()));
}

