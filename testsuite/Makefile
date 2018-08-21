testexe = sks-attr.exe
rootdir = /cygdrive/d/develop/sks
bindir = $(rootdir)/bin
incdir = $(rootdir)/include
incdepdir = /cygdrive/d/develop
libdir = $(rootdir)/lib
libname = sks
libsta = lib$(libname).a
libdyn = cyg$(libname).dll

CXX = g++
CXXINC = -I$(incdepdir) -I$(incdir)
CXXFLAGS = -std=gnu++17 -g3 $(CXXINC)
LIBS = -l$(libname) -L$(libdir)

all: check

re: clean all

check: $(testexe)

$(testexe): %.exe: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LIBS)
	./$@

clean:
	rm -f *.exe
