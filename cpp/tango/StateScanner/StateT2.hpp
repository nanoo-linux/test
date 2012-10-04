#pragma once

#include "State.hpp"

class StateT2: public State
{
	public:
		StateT2(pData);
		void do_target();
		pState next_state();
	private:
		
};
