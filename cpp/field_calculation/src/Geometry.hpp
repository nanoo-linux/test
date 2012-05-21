#pragma once

#include "RFile.hpp"
#include "Exception.hpp"
#include "PointCharge.hpp"
#include <vector>
#include <utility>

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
		std::pair <int, int> size() const;
	private:
		bool readOnePoint(RFile &);
		void readSize(RFile &);
		std::vector <PointCharge> points_;
		std::pair <int, int> size_;
};
