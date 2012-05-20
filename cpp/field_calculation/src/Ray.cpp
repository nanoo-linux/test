#include "Ray.hpp"
#include <cmath>

/*
 *
 *
 *    ^
 *    |
 *    |
 *    |
 *    |
 *    |                              . · ˙
 *    |                  V     . · ˙
 *   y|                  . · ˙
 *    |            . · ˙
 *    |       . · ˙   \   phi
 *    | . · ˙         |
 *    +-------------------------------------------------->
 *                        x
 *
 */

Ray::Ray(double x, double y, double phi, double E)
: r_(x, y), V_(sqrt(E*2/EMASS)*cos(phi), sqrt(E*2/EMASS)*sin(phi))
{}

Vector Ray::r() const
{
	return r_;
}

Vector Ray::V() const
{
	return V_;
}

Ray &Ray::r(Vector &q)
{
	r_ = q;
	return *this;
}

Ray &Ray::V(Vector &V)
{
	V_ = V;
	return *this;
}

Ray &Ray::applyF(Vector &F, double dt)
{
	Vector dV(F);
	dV *= ECHARGE/EMASS;
	dV *= dt;
	V_ += dV;
	r_ += V_*dt;
	return *this;
}
