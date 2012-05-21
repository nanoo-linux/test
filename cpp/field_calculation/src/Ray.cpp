#include "Ray.hpp"
#include <cmath>



#include <cstdio>

/*
 *
 *    ^
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

Vector &Ray::r()
{
	return r_;
}

Vector &Ray::V()
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

Ray &Ray::applyEstaticF(Vector dV, double dt)
{
	puts(r_.str().c_str());
	dV *= ECHARGE/EMASS;
	dV *= dt;
	V_ += dV;
	r_ += V_*dt;
	puts(r_.str().c_str());
	return *this;
}
