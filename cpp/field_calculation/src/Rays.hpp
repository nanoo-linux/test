#pragma once

#include "Ray.hpp"
#include "Exception.hpp"

class RaysException: public Exception
{
	public:
		RaysException(const char *s, int c=-1): Exception(s, c) {}
};

class Rays
{
	public:
		Rays(const char *, double e=-1.6e-19);
		Rays(const Rays &);
		std::vector <Ray> &rays();
		double charge() const;
	private:
		bool readOneRay(RFile &);
		std::vector <Ray> rays_;
		double charge_;
};


