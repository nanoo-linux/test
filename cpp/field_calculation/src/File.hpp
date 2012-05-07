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
		File &addString(const std::string &);
		File &addString(const char *);
		File &addInt(int);
		File &addLF();
	private:
		FILE *file_;
};
