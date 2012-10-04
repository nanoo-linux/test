#pragma once

#include "State.hpp"

class StateSet: public State
{
	public:
		StateSet(pData);
		void do_target();
		pState next_state();
	private:
		
};

