#pragma once

#include "Exception.hpp"
#include "PointCharge.hpp"
#include <vector>

class GeometryException: public Exception
{
	public:
		GeometryException(const char *s, int c=-1): Exception(s, c) {}
};

class iGeometry
{
	public:
		virtual ~iGeometry() {}
		virtual std::vector <PointCharge> points() = 0;
};
