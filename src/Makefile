object = version.o attr.o style.o offen.o script.o skill.o analyze.o file.o
binobj = main.o
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
LIBS = -l$(libname) -L$(bindir)

all: lib install-lib bin install-bin

re: clean all

bin: $(binobj)
	$(CXX) $(CXXFLAGS) $(binobj) $(LIBS) -o sks.exe

lib: $(object)
	$(AR) cru $(libsta) $(object)
	$(CXX) $(CXXFLAGS) $(object) -fPIC -shared -o $(libdyn)

$(object): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(binobj): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

install-bin:
	mkdir -p $(bindir)
	cp sks.exe $(bindir)

install-lib:
	mkdir -p $(bindir) $(libdir)
	cp $(libsta) $(libdir)
	cp $(libdyn) $(bindir)

clean: clean-bin clean-lib

clean-bin:
	rm -f *.exe

clean-lib:
	rm -f *.a *.o *.dll
