#pragma once

#include <exception>
#include <string>

#define STR_(x) #x
#define STR(x) STR_(x)

class Exception: public std::exception
{
	public:
		Exception(const char *s, int c): what_(s), code_(c) {}
		virtual ~Exception() throw() {}
		const char *what() const throw() {return what_.c_str();}
		int code() throw() {return code_;}
	private:
		std::string what_;
		int code_;
};
