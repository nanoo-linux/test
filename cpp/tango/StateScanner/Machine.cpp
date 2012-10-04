#include "Machine.hpp"
#include "StateT1.hpp"
#include <algorithm>

Machine::Machine(std::string a, std::string b, StateScanner *master)
{
	pData data(new Data(a, b, master));
	state_.reset(new StateT1(data));
}

void Machine::do_target()
{
	state_->do_target();
	state_ = state_->next_state();
}

void Machine::do_start()
{
	interrupt_requested_ = false;
	thread_ = std::thread(this);
	thread_.detach();
}

void Machine::do_stop()
{
	interrupt_requested = true;
}

bool Machine::finished()
{
	return state_->data()->finished;
}

pData Machine::data() const
{
	return state_->data();
}

void Machine::update_spectrum(double *a, size_t b)
{
	data->give_me_spectrum_baby(a, b);
}

void Machine::operator ()()
{
	while (!interrupt_requested_) {
		do_target();
		if (finished()) {
			return;
		}
	}
}
