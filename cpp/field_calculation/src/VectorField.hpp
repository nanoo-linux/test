#pragma once

#include "Field.hpp"
#include "Exception.hpp"
#include "Pgm.hpp"
#include <vector>
#include <utility>

using std::vector;
using std::pair;

class VectorFieldException: public Exception
{
	public:
		VectorFieldException(const char *s, int c=-1): Exception(s, c) {}
};

class VectorField
{
	public:
		VectorField(const Field &);
		pair <double, double> operator ()(int, int);
		Pgm pgm() const;
	private:
		int x_;
		int y_;
		double max_;
		vector <vector <pair <double, double> > > v_;
};
