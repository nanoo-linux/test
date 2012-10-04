#pragma once

#include "State.hpp"
#include "Data.hpp"
#include <string>
#include <thread>

typedef std::shared_ptr <Tango::DeviceProxy> DevProxy;
class StateScanner;

class Machine
{
	public:
		Machine(std::string, std::string, StateScanner *);
		void do_target();
		bool finished();
		void do_start();
		void do_stop();
		pData data() const;
		void update_spectrum(double *, size_t);
		void operator ()(DevProxy, DevProxy);
	private:
		pState state_;
		bool interrupt_requested_;
		std::thread thread_;
};
