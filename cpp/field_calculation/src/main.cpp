
#include "Engine.hpp"
#include "Geometry.hpp"
#include "Rays.hpp"
#include <utility>
using std::pair;
using std::make_pair;

int main()
{
	Geometry g("electrodes.txt");
	Rays r("rays.txt");
	Engine e(g, r);
	File out("dump.txt");
	e.simulate().save(out);
}
