#pragma once

#include "State.hpp"

class StateT1: public State
{
	public:
		StateT1(pData);
		void do_target();
		pState next_state();
	private:
		
};
