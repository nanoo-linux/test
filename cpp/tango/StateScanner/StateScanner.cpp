/*----- PROTECTED REGION ID(StateScanner.cpp) ENABLED START -----*/
static const char *RcsId = "$Id:  $";
//=============================================================================
//
// file :        StateScanner.cpp
//
// description : C++ source for the StateScanner and its commands.
//               The class is derived from Device. It represents the
//               CORBA servant object which will be accessed from the
//               network. All commands which can be executed on the
//               StateScanner are implemented in this file.
//
// project :     .
//
// $Author:  $
//
// $Revision:  $
// $Date:  $
//
// SVN only:
// $HeadURL:  $
//
// CVS only:
// $Source:  $
// $Log:  $
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#include <StateScanner.h>
#include <StateScannerClass.h>

/*----- PROTECTED REGION END -----*/


/**
 *	StateScanner class description:
 *	
 */

//================================================================
//
//  The following table gives the correspondence
//  between command and method names.
//
//  Command name  |  Method name
//----------------------------------------------------------------
//  State         |  Inherited (no method)
//  Status        |  Inherited (no method)
//  Start         |  start
//  Stop          |  stop
//  Save          |  save
//================================================================

namespace StateScanner_ns
{
	/*----- PROTECTED REGION ID(StateScanner::namespace_starting) ENABLED START -----*/

	//	static initializations

	/*----- PROTECTED REGION END -----*/	//	StateScanner::namespace_starting



//--------------------------------------------------------
/**
 *	Method      : StateScanner::StateScanner()
 *	Description : Constructors for a Tango device
 *	              implementing the class StateScanner
 */
//--------------------------------------------------------
StateScanner::StateScanner(Tango::DeviceClass *cl, string &s)
 	: Tango::Device_4Impl(cl, s.c_str())
{
	/*----- PROTECTED REGION ID(StateScanner::constructor_1) ENABLED START -----*/

	init_device();

	/*----- PROTECTED REGION END -----*/	//	StateScanner::constructor_1
}
//--------------------------------------------------------
StateScanner::StateScanner(Tango::DeviceClass *cl, const char *s)
 	: Tango::Device_4Impl(cl, s)
{
	/*----- PROTECTED REGION ID(StateScanner::constructor_2) ENABLED START -----*/

	init_device();

	/*----- PROTECTED REGION END -----*/	//	StateScanner::constructor_2
}
//--------------------------------------------------------
StateScanner::StateScanner(Tango::DeviceClass *cl, const char *s, const char *d)
 	: Tango::Device_4Impl(cl, s, d)
{
	/*----- PROTECTED REGION ID(StateScanner::constructor_3) ENABLED START -----*/

	init_device();

	/*----- PROTECTED REGION END -----*/	//	StateScanner::constructor_3
}


//--------------------------------------------------------
/**
 *	Method      : StateScanner::delete_device()()
 *	Description : will be called at device destruction or at init command
 */
//--------------------------------------------------------
void StateScanner::delete_device()
{
	/*----- PROTECTED REGION ID(StateScanner::delete_device) ENABLED START -----*/
	machine_.reset();
	//	Delete device allocated objects

	/*----- PROTECTED REGION END -----*/	//	StateScanner::delete_device
	delete[] attr_Delta1_read;
	delete[] attr_Delta2_read;
	delete[] attr_VDelta_read;
	delete[] attr_VStart_read;
	delete[] attr_VStop_read;
	delete[] attr_Actuator_read;
	delete[] attr_Sensor_read;
	delete[] attr_Spectrum_read;
	
}


//--------------------------------------------------------
/**
 *	Method      : StateScanner::init_device()
 *	Description : //	will be called at device initialization.
 */
//--------------------------------------------------------
void StateScanner::init_device()
{
	DEBUG_STREAM << "StateScanner::init_device() create device " << device_name << endl;

	
	attr_Delta1_read = new Tango::DevULong[1];
	attr_Delta2_read = new Tango::DevULong[1];
	attr_VDelta_read = new Tango::DevDouble[1];
	attr_VStart_read = new Tango::DevDouble[1];
	attr_VStop_read = new Tango::DevDouble[1];
	attr_Actuator_read = new Tango::DevString[1];
	attr_Sensor_read = new Tango::DevString[1];
	attr_Spectrum_read = new Tango::DevDouble[2048];
	
	/*----- PROTECTED REGION ID(StateScanner::init_device) ENABLED START -----*/
	machine_.reset(new Machine);
	//	Initialize device

	/*----- PROTECTED REGION END -----*/	//	StateScanner::init_device
}



//--------------------------------------------------------
/**
 *	Method      : StateScanner::always_executed_hook()
 *	Description : method always executed before any command is executed
 */
//--------------------------------------------------------
void StateScanner::always_executed_hook()
{
	INFO_STREAM << "StateScanner::always_executed_hook()  " << device_name << endl;
	/*----- PROTECTED REGION ID(StateScanner::always_executed_hook) ENABLED START -----*/

	//	code always executed before all requests

	/*----- PROTECTED REGION END -----*/	//	StateScanner::always_executed_hook
}



//--------------------------------------------------------
/**
 *	Method      : StateScanner::read_attr_hardware()
 *	Description : Hardware acquisition for attributes.
 */
//--------------------------------------------------------
void StateScanner::read_attr_hardware(vector<long> &attr_list)
{
	DEBUG_STREAM << "StateScanner::read_attr_hardware(vector<long> &attr_list) entering... " << endl;
	/*----- PROTECTED REGION ID(StateScanner::read_attr_hardware) ENABLED START -----*/

	//	Add your own code

	/*----- PROTECTED REGION END -----*/	//	StateScanner::read_attr_hardware

}


//--------------------------------------------------------
/**
 *	Read Delta1 attribute
 *	Description: 
 *
 *	Data type:	Tango::DevULong
 *	Attr type:	Scalar 
 */
//--------------------------------------------------------
void StateScanner::read_Delta1(Tango::Attribute &attr)
{
	DEBUG_STREAM << "StateScanner::read_Delta1(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(StateScanner::read_Delta1) ENABLED START -----*/
	pData d = machine_->data();
	attr_Dalta1_read[0] = d->delta1;

	//	Set the attribute value
	attr.set_value(attr_Delta1_read);
	/*----- PROTECTED REGION END -----*/	//	StateScanner::read_Delta1
}

//--------------------------------------------------------
/**
 *	Write Delta1 attribute values to hardware.
 *
 *	Data type:	Tango::DevULong
 *	Attr type:	Scalar 
 */
//--------------------------------------------------------
void StateScanner::write_Delta1(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "StateScanner::write_Delta1(Tango::Attribute &attr) entering... " << endl;
	
	//	Retrieve write value
	Tango::DevULong	w_val;
	attr.get_write_value(w_val);
	
	/*----- PROTECTED REGION ID(StateScanner::write_Delta1) ENABLED START -----*/
	pData d = machine_->data();
	d->delta1 = w_val;
	

	/*----- PROTECTED REGION END -----*/	//	StateScanner::write_Delta1
}

//--------------------------------------------------------
/**
 *	Read Delta2 attribute
 *	Description: 
 *
 *	Data type:	Tango::DevULong
 *	Attr type:	Scalar 
 */
//--------------------------------------------------------
void StateScanner::read_Delta2(Tango::Attribute &attr)
{
	DEBUG_STREAM << "StateScanner::read_Delta2(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(StateScanner::read_Delta2) ENABLED START -----*/
	pData d = machine_->data();
	attr_Delta2_read[0] = d->delta2;
	//	Set the attribute value
	attr.set_value(attr_Delta2_read);

	/*----- PROTECTED REGION END -----*/	//	StateScanner::read_Delta2
}

//--------------------------------------------------------
/**
 *	Write Delta2 attribute values to hardware.
 *
 *	Data type:	Tango::DevULong
 *	Attr type:	Scalar 
 */
//--------------------------------------------------------
void StateScanner::write_Delta2(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "StateScanner::write_Delta2(Tango::Attribute &attr) entering... " << endl;
	
	//	Retrieve write value
	Tango::DevULong	w_val;
	attr.get_write_value(w_val);
	
	/*----- PROTECTED REGION ID(StateScanner::write_Delta2) ENABLED START -----*/
	pData d = machine_->data();
	d->delta2 = w_val;
	

	/*----- PROTECTED REGION END -----*/	//	StateScanner::write_Delta2
}

//--------------------------------------------------------
/**
 *	Read VDelta attribute
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar 
 */
//--------------------------------------------------------
void StateScanner::read_VDelta(Tango::Attribute &attr)
{
	DEBUG_STREAM << "StateScanner::read_VDelta(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(StateScanner::read_VDelta) ENABLED START -----*/
	pData d = machine_->data();
	attr_VDelta_read[0] = d->vdelta;
	//	Set the attribute value
	attr.set_value(attr_VDelta_read);

	/*----- PROTECTED REGION END -----*/	//	StateScanner::read_VDelta
}

//--------------------------------------------------------
/**
 *	Write VDelta attribute values to hardware.
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar 
 */
//--------------------------------------------------------
void StateScanner::write_VDelta(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "StateScanner::write_VDelta(Tango::Attribute &attr) entering... " << endl;
	
	//	Retrieve write value
	Tango::DevDouble	w_val;
	attr.get_write_value(w_val);
	
	/*----- PROTECTED REGION ID(StateScanner::write_VDelta) ENABLED START -----*/
	pData d = machine_->data();
	d->vdelta = w_val;

	/*----- PROTECTED REGION END -----*/	//	StateScanner::write_VDelta
}

//--------------------------------------------------------
/**
 *	Read VStart attribute
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar 
 */
//--------------------------------------------------------
void StateScanner::read_VStart(Tango::Attribute &attr)
{
	DEBUG_STREAM << "StateScanner::read_VStart(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(StateScanner::read_VStart) ENABLED START -----*/
	pData d = machine_->data();
	attr_VStart_read[0] = d->vstart;
	//	Set the attribute value
	attr.set_value(attr_VStart_read);

	/*----- PROTECTED REGION END -----*/	//	StateScanner::read_VStart
}

//--------------------------------------------------------
/**
 *	Write VStart attribute values to hardware.
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar 
 */
//--------------------------------------------------------
void StateScanner::write_VStart(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "StateScanner::write_VStart(Tango::Attribute &attr) entering... " << endl;
	
	//	Retrieve write value
	Tango::DevDouble	w_val;
	attr.get_write_value(w_val);
	
	/*----- PROTECTED REGION ID(StateScanner::write_VStart) ENABLED START -----*/
	pData d = machine_->data();
	d->vstart = w_val;
	

	/*----- PROTECTED REGION END -----*/	//	StateScanner::write_VStart
}

//--------------------------------------------------------
/**
 *	Read VStop attribute
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar 
 */
//--------------------------------------------------------
void StateScanner::read_VStop(Tango::Attribute &attr)
{
	DEBUG_STREAM << "StateScanner::read_VStop(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(StateScanner::read_VStop) ENABLED START -----*/
	pData d = machine_->data();
	attr_VStop_read[0] = d->vstop;
	//	Set the attribute value
	attr.set_value(attr_VStop_read);

	/*----- PROTECTED REGION END -----*/	//	StateScanner::read_VStop
}

//--------------------------------------------------------
/**
 *	Write VStop attribute values to hardware.
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Scalar 
 */
//--------------------------------------------------------
void StateScanner::write_VStop(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "StateScanner::write_VStop(Tango::Attribute &attr) entering... " << endl;
	
	//	Retrieve write value
	Tango::DevDouble	w_val;
	attr.get_write_value(w_val);
	
	/*----- PROTECTED REGION ID(StateScanner::write_VStop) ENABLED START -----*/
	pData d = machine_->data();
	d->vstop = w_val;
	

	/*----- PROTECTED REGION END -----*/	//	StateScanner::write_VStop
}

//--------------------------------------------------------
/**
 *	Read Actuator attribute
 *	Description: 
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar 
 */
//--------------------------------------------------------
void StateScanner::read_Actuator(Tango::Attribute &attr)
{
	DEBUG_STREAM << "StateScanner::read_Actuator(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(StateScanner::read_Actuator) ENABLED START -----*/
	pData d = machine_->data();
	attr_Actuator_read[0] = d->name_actuator;
	//	Set the attribute value
	attr.set_value(attr_Actuator_read);

	/*----- PROTECTED REGION END -----*/	//	StateScanner::read_Actuator
}

//--------------------------------------------------------
/**
 *	Write Actuator attribute values to hardware.
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar 
 */
//--------------------------------------------------------
void StateScanner::write_Actuator(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "StateScanner::write_Actuator(Tango::Attribute &attr) entering... " << endl;
	
	//	Retrieve write value
	Tango::DevString	w_val;
	attr.get_write_value(w_val);
	
	/*----- PROTECTED REGION ID(StateScanner::write_Actuator) ENABLED START -----*/
	pData d = machine_->data();
	d->name_actuator = w_val;
	d->update_proxies();

	/*----- PROTECTED REGION END -----*/	//	StateScanner::write_Actuator
}

//--------------------------------------------------------
/**
 *	Read Sensor attribute
 *	Description: 
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar 
 */
//--------------------------------------------------------
void StateScanner::read_Sensor(Tango::Attribute &attr)
{
	DEBUG_STREAM << "StateScanner::read_Sensor(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(StateScanner::read_Sensor) ENABLED START -----*/
	pData d = machine_->data();
	attr_Sensor_read[0] = d->name_sensor;
	//	Set the attribute value
	attr.set_value(attr_Sensor_read);

	/*----- PROTECTED REGION END -----*/	//	StateScanner::read_Sensor
}

//--------------------------------------------------------
/**
 *	Write Sensor attribute values to hardware.
 *
 *	Data type:	Tango::DevString
 *	Attr type:	Scalar 
 */
//--------------------------------------------------------
void StateScanner::write_Sensor(Tango::WAttribute &attr)
{
	DEBUG_STREAM << "StateScanner::write_Sensor(Tango::Attribute &attr) entering... " << endl;
	
	//	Retrieve write value
	Tango::DevString	w_val;
	attr.get_write_value(w_val);
	
	/*----- PROTECTED REGION ID(StateScanner::write_Sensor) ENABLED START -----*/
	pData d = machine_->data();
	d->name_sensor = w_val;
	d->update_proxies();

	/*----- PROTECTED REGION END -----*/	//	StateScanner::write_Sensor
}

//--------------------------------------------------------
/**
 *	Read Spectrum attribute
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Spectrum  max = 2048
 */
//--------------------------------------------------------
void StateScanner::read_Spectrum(Tango::Attribute &attr)
{
	DEBUG_STREAM << "StateScanner::read_Spectrum(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(StateScanner::read_Spectrum) ENABLED START -----*/
	machine_->update_spectrum(attr_Spectrum_read, 2048);
	//	Set the attribute value
	attr.set_value(attr_Spectrum_read, 2048);

	/*----- PROTECTED REGION END -----*/	//	StateScanner::read_Spectrum
}

//--------------------------------------------------------
/**
 *	Method      : StateScanner::StateScannerClass::add_dynamic_attributes()
 *	Description : Create the dynamic attributes if any
 *	              for specified device.
 */
//--------------------------------------------------------
void StateScanner::add_dynamic_attributes()
{
	/*----- PROTECTED REGION ID(StateScanner::Class::add_dynamic_attributes) ENABLED START -----*/

	//	Add your own code to create and add dynamic attributes if any

	/*----- PROTECTED REGION END -----*/	//	StateScanner::Class::add_dynamic_attributes

}



//========================================================
//	Command execution methods
//========================================================

//--------------------------------------------------------
/**
 *	Execute the Start command:
 *	Description: 
 *
 *	@param argin 
 *	@returns 
 */
//--------------------------------------------------------
void StateScanner::start()
{
	DEBUG_STREAM << "StateScanner::Start()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(StateScanner::start) ENABLED START -----*/

	//	Add your own code
	machine_->do_start();
	setState(Tango::RUNNING);
	/*----- PROTECTED REGION END -----*/	//	StateScanner::start

}

//--------------------------------------------------------
/**
 *	Execute the Stop command:
 *	Description: 
 *
 *	@param argin 
 *	@returns 
 */
//--------------------------------------------------------
void StateScanner::stop()
{
	DEBUG_STREAM << "StateScanner::Stop()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(StateScanner::stop) ENABLED START -----*/

	//	Add your own code
	machine_->do_stop();
	setState(Tango::ON);
	/*----- PROTECTED REGION END -----*/	//	StateScanner::stop

}

//--------------------------------------------------------
/**
 *	Execute the Save command:
 *	Description: 
 *
 *	@param argin 
 *	@returns 
 */
//--------------------------------------------------------
void StateScanner::save()
{
	DEBUG_STREAM << "StateScanner::Save()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(StateScanner::save) ENABLED START -----*/

	//	Add your own code
	
	machine_->data()->save();
	/*----- PROTECTED REGION END -----*/	//	StateScanner::save

}


	/*----- PROTECTED REGION ID(StateScanner::namespace_ending) ENABLED START -----*/

	//	Additional Methods

	/*----- PROTECTED REGION END -----*/	//	StateScanner::namespace_ending
} //	namespace