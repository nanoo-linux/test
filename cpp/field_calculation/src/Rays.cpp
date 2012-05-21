#include "Rays.hpp"
#include "RFile.hpp"
#include <vector>
#include <cstdio>
#include <cmath>

using std::vector;

Rays::Rays(const char *file)
{
	try {
		RFile f(file);
		while (readOneRay(f));
	} catch (RFileException &e) {
		throw RaysException(e.what());
	}
}

Rays::Rays(const Rays &r)
: rays_(r.rays_)
{}

vector <Ray> &Rays::rays()
{
	return rays_;
}

bool Rays::readOneRay(RFile &f)
{
	double x;
	double y;
	double phi;
	double E;
	try {
		x = f.readDouble();
		y = f.readDouble();
		phi = f.readDouble();
		phi *= 180/M_PI;
		E = f.readDouble();
	} catch (RFileException &e) {
		return false;
	}
	rays_.push_back(Ray(x, y, phi, E));
	return true;
}
