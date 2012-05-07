#include "Rays.hpp"
#include <vector>
#include "RFile.hpp"
#include <cstdio>

using std::vector;

Rays::Rays(const char *file, double e)
: charge_(e)
{
	try {
		RFile f(file);
		while (readOneRay(f));
	} catch (RFileException &e) {
		throw RaysException(e.what());
	}
}

Rays::Rays(const Ray &r)
{
	//TODO:
}

vector <Ray> &Rays::ray()
{
	return rays_;
}

bool Rays::readOneRay(RFile &f)
{
	try {
		//TODO:
	} catch (RFileException &e) {
		return false;
	}
	rays_.push_back(Ray(/*…*/));
	return true;
}

double Rays::charge() const
{
	return charge_;
}
