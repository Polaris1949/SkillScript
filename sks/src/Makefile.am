AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = sks
sks_SOURCES = main.cc message.cc
sks_DEPENDENCIES = libsks.la
AM_CXXFLAGS = -std=gnu++2a -I$(srcdir)/../include -I$(srcdir)/../../libsks/include
AM_LDFLAGS = -lsks -L.

libsks.la:
	libtool --mode=install cp $(builddir)/../../libsks/src/libsks.la $(shell pwd)/libsks.la
	libtool --mode=finish $(shell pwd)
