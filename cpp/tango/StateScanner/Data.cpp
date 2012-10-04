#include "Data.hpp"
#include <algorithm>

Data::Data(std::string dev_act, std::string dev_sen, StateScanner *m)
: finished(false), master_(m)
{
	name_actuator = dev_act;
	name_sensor = dev_sen;
	update_proxies();
}

void Data::save()
{
	//TODO:
}

void Data::give_me_spectrum_baby(double *ptr, size_t s1)
{
	size_t s2 = std::max(s1, spectrum.size());
	for (size_t i=0; i<s2; ++i) {
		ptr[i] = spectrum[i];
	}
}

void Data::update_proxies()
{
	dev_actuator.reset(new Tango::DeviceProxy(name_actuator.c_str()));
	dev_sensor.reset(new Tango::DeviceProxy(name_sensor.c_str()));
}

void Data::reinitialize()
{
	current_vvalue = vstart;
	dev_actuator->set_value(); //TODO: start value
}
