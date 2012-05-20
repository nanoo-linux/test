#pragma once

#include "Exception.hpp"
#include "File.hpp"
#include <vector>

using std::vector;

class PgmException: public Exception
{
	public:
		PgmException(const char *s, int c=-1): Exception(s, c) {}
};

class Pgm
{
	public:
		Pgm(const int x, const int y, const int depth=0xffff);
		Pgm &setPixel(const int x, const int y, const int color);
		Pgm &incPixel(const int x, const int y);
		void save(File &);
	private:
		const int x_;
		const int y_;
		const int depth_;
		vector <vector <int> > image_;
};
