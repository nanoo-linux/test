#include "Engine.hpp"

Engine::Engine(Geometry &g, Rays &r)
: g_(g), r_(r)
{}

Engine &Engine::simulate()
{
	std::vector <Ray> rays = r_.rays();
	std::vector <Ray> ::iterator it = rays.begin();
	while (!rays.empty()) {
		while (it!=rays.end()) {
			//take force;
			//apply to ray;
			//if ray is on the screen
				//put dot on screen and remove ray
			//if ray is out of space
				//remove ray


		}
	}
	return *this;
}

Pgm Engine::pgm()
{
	return Pgm(100, 100);
}
