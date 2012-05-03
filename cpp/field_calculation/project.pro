TEMPLATE = app
TARGET = ficmp

CONFIG -= qt
OBJECTS_DIR = obj

SOURCES += src/main.cpp \
		src/Field.cpp \
		src/File.cpp \
		src/Pgm.cpp

HEADERS += src/Pgm.hpp \
		src/File.hpp \
		src/Field.hpp \
		Exception.hpp \
