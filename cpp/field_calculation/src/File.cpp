#include "File.hpp"

#include <sstream>

File::File(const char *fname)
{
	file_ = fopen(fname, "w");
	if (file_ < 0) {
		throw FileException(__FILE__ ":" STR(__LINE__) ": Could not open file to write");
	}
}

File::~File()
{
	fclose(file_);
}

const File &File::addString(const char *s) const
{
	fprintf(file_, "%s", s);
	return *this;
}

const File &File::addString(const std::string &s) const
{
	return addString(s.c_str());
}

const File &File::addInt(int a) const
{
	std::stringstream s;
	s << a;
	return addString(s.str());
}

const File &File::addLF() const
{
	return addString("\n");
}

