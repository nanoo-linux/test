#pragma once

#include "Ray.hpp"
#include "Exception.hpp"
#include "RFile.hpp"
#include <vector>

using std::vector;

class RaysException: public Exception
{
	public:
		RaysException(const char *s, int c=-1): Exception(s, c) {}
};

class Rays
{
	public:
		Rays(const char *);
		Rays(const Rays &);
		std::vector <Ray> &rays();
	private:
		bool readOneRay(RFile &);
		std::vector <Ray> rays_;
};


