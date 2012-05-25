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
: r_(x, y), V_(sqrt(fabs(E*2/EMASS))*cos(phi), sqrt(fabs(E*2/EMASS))*sin(phi))
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
	dV *= ECHARGE/EMASS;
	dV *= dt;
	V_ += dV;
	r_ += (V_*dt);
	printf("%s\n", r_.str().c_str());
	return *this;
}
