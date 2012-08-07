#pragma once

#include <pthread.h>
#include <exception>
#include "iEventShooter.hpp"

class SerialPortException: public std::exception
{
	public:
		SerialPortException()
			: std::exception(), what_("port error") {}
		~SerialPortException() throw() {}
		const char *what() throw() {return what_.c_str();}
	private:
		std::string what_;
};

class SerialPort
{
	public:
		SerialPort(const char *, iEventShooter &);
		~SerialPort();
	private:
		void thread_main();
		static void *thread_starter(void *);
		thread_t threadID_;
		int df_[2];
		int sf_;
		iEventShooter &ev_;
		bool open_port(const char *);
		void close_port();
		bool open_df();
		void close_df();
		void read_port();
};

template <typename T>
class Array
{
	public:
		Array(size_t);
		~Array();
		T *get() const;
	private:
		T *ptr_;
};

template <typename T>
Array<T>::Array(size_t ss)
{
	ptr_ = new T [ss];
}

template <typename T>
Array<T>::~Array()
{
	delete [] ptr_;
}

template <typename T>
T *Array<T>::get() const
{
	return ptr_;
}

