#pragma once

#include <memory>
#include <vector>
#include <string>
#include <tango.h>

class StateScanner;

class Data
{
	public:
		Data(std::string, std::string, StateScanner *);
		void reinitialize();
		unsigned delta1;
		unsigned delta2;
		double vdelta;
		double vstart;
		double vstop;
		double current_vvalue;
		vector <double> spectrum;
		void save();
		void give_me_spectrum_baby(double *, size_t);
		void update_proxies();
		std::string name_actuator;
		std::string name_sensor;
		std::shared_ptr <Tango::DeviceProxy> dev_actuator;
		std::shared_ptr <Tango::DeviceProxy> dev_sensor;
		bool finished;
		StateScanner *master_;
};

typedef std::shared_ptr <Data> pData;
