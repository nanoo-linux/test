#pragma once

#include "Vector.hpp"

const double EMASS = 9.10938188e10-31;
const double ECHARGE = -1.6e-19;

class Ray
{
	public:
		Ray(double, double, double, double);
		Vector r() const;
		Vector V() const;
		Ray &r(Vector &);
		Ray &V(Vector &);
		Ray &applyF(Vector &, double dt);
	private:
		Vector r_;
		Vector V_;
};
