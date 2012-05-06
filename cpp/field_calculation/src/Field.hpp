#pragma once

#include "Pgm.hpp"
#include "Exception.hpp"
#include <vector>
#include <utility>

using std::vector;
using std::pair;

class FieldException: public Exception
{
	public:
		FieldException(const char *s, int c=-1): Exception(s, c) {}
};

class Field
{
	public:
		Field(int x, int y, pair <double, double> mesh);
		Field &addQ(int x, int y, double voltage);
		Field &refine(int times=1000);
		pair <int, int> size() const;
		Pgm pgm() const;
		const pair <double, double> mesh() const;
		pair <bool, double> operator()(int x, int y) const;
		bool refined() const;
	private:
		int x_;
		int y_;
		int max_;
		int min_;
		bool refined_;
		vector <vector <pair <bool, double> > > v_;
		const pair <double, double> mesh_;
};
