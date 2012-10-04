#pragma once

#include "State.hpp"

class StateMes: public State
{
	public:
		StateMes(pData);
		void do_target();
		pState next_state();
	private:
		
};
