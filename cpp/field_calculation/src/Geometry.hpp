#pragma once

#include "RFile.hpp"
#include "Exception.hpp"
#include "PointCharge.hpp"
#include <vector>

class GeometryException: public Exception
{
	public:
		GeometryException(const char *s, int c=-1): Exception(s, c) {}
};

class Geometry
{
	public:
		Geometry(const char *);
		std::vector <PointCharge> &points();
	private:
		bool readOnePoint(RFile &);
		std::vector <PointCharge> points_;
};
