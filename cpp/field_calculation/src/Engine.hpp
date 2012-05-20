#pragma once

#include "Geometry.hpp"
#include "Exception.hpp"
#include "Pgm.hpp"
#include "Rays.hpp"
#include <vector>

using std::vector;

class EngineException: public Exception
{
	public:
		EngineException(const char *s, int c=-1): Exception(s, c) {}
};

class Engine
{
	public:
		Engine(Geometry &, Rays &);
		Engine &simulate();
		Pgm pgm();
	private:
		Geometry &g_;
		Rays &r_;
		bool simulated_;
		vector <vector <double> > screen_image_;
};
