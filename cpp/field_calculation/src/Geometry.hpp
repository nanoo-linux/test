#pragma once

#include "iGeometry.hpp"
#include "RFile.hpp"
#include <vector>

class Geometry: public iGeometry
{
	public:
		Geometry(const char *);
		std::vector <PointCharge> points();
	private:
		bool readOnePoint(RFile &);
		std::vector <PointCharge> points_;
};
