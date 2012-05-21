#pragma once

#include "Geometry.hpp"
#include "Exception.hpp"
#include "Pgm.hpp"
#include "Rays.hpp"
#include "Field.hpp"
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
		Engine &save(File &);
		Pgm pgm();
	private:
		Geometry &g_;
		Rays &r_;
		bool simulated_;
		int screen_x_;
		vector <long long> screen_;
		Field prepare_field();
};
