#pragma once

#include <memory>
#include "Data.hpp"

class State;
typedef std::tr1::shared_ptr <State> pState;

class State
{
	public:
		State(pData data): data_(data) {}
		virtual ~State() {}
		virtual void do_target() = 0;
		virtual pState next_state() = 0;
		pData data() {
			return data_;
		}
	protected:
		pData data_;
};

