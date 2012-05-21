#pragma once

#include "Field.hpp"
#include "Exception.hpp"
#include "Pgm.hpp"
#include "Vector.hpp"
#include <vector>

using std::vector;

class VectorFieldException: public Exception
{
	public:
		VectorFieldException(const char *s, int c=-1): Exception(s, c) {}
};

class VectorField
{
	public:
		VectorField(const Field &);
		Vector operator ()(int, int);
		Vector operator ()(Vector &);
		Pgm pgm() const;
	private:
		int x_;
		int y_;
		double max_;
		vector <vector <Vector> > v_;
};
