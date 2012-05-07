#include "Engine.hpp"

Engine::Engine(Geometry &g, Rays r)
: g_(g), r_(r)
{}

Engine &Engine::simulate()
{
	std::vector <Ray> ::iterator it = r_.begin();
	while (!r_.empty()) {
		while (it!=r_.end()) {
			//take force;
			//apply to ray;
			//if ray is on the screen
				//remove ray
		}

	}
}

Pgm Engine::pgm()
{
}
