AUTOMAKE_OPTIONS = foreign
LIBVER = 1:1:0

LIBTOOL = /bin/libtool
lib_LTLIBRARIES = libsks.la
libsks_la_SOURCES = \
    analyze.cc \
    attr.cc \
    file.cc \
    offen.cc \
    script.cc \
    skill.cc \
    style.cc \
    version.cc
libsks_la_LDFLAGS = -version-info $(LIBVER) -no-undefined

AM_CXXFLAGS = -std=gnu++2a -I$(srcdir)/../include
