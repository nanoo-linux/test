#include "Engine.hpp"
#include "Geometry.hpp"

int main()
{
	Engine e;
	Geometry g("electrodes.txt");
	e.setGeometry(g).simulate.saveImage(File("dump.pgm"));
}
