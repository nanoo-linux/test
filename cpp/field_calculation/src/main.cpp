
#include "Engine.hpp"
#include "Geometry.hpp"
#include "Rays.hpp"

int main()
{
	Geometry g("electrodes.txt");
	Rays r("rays.txt");
	Engine e(g, r);
	File out("dump.pgm");
	e.simulate().pgm().save(out);
}
