#pragma once

#include "Exception.hpp"
#include <string>
#include <cstdio>

class FileException: public Exception
{
	public:
		FileException(const char *s, int c=-1): Exception(s, c) {}
};

class File
{
	public:
		File(const char *);
		~File();
		const File &addString(const std::string &) const;
		const File &addString(const char *) const;
		const File &addInt(int) const;
		const File &addLF() const;
	private:
		FILE *file_;
};
