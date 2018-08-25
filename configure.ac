#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

m4_include(config/acx.m4)
m4_include(config/proginstall.m4)
m4_include(config/elf.m4)
m4_include([libtool.m4])
m4_include([ltoptions.m4])
m4_include([ltsugar.m4])
m4_include([ltversion.m4])
m4_include([lt~obsolete.m4])

AC_PREREQ(2.69)
AC_INIT(skill-script, 1.1.0, BeiChen1949@gmail.com)

# AM_INIT_AUTOMAKE

# Find the build, host, and target systems.
ACX_NONCANONICAL_BUILD
ACX_NONCANONICAL_HOST
ACX_NONCANONICAL_TARGET

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX

dnl Autoconf 2.5x and later will set a default program prefix if
dnl --target was used, even if it was the same as --host.  Disable
dnl that behavior.  This must be done before AC_CANONICAL_SYSTEM
dnl to take effect.
test "$host_noncanonical" = "$target_noncanonical" &&
  test "$program_prefix$program_suffix$program_transform_name" = \
    NONENONEs,x,x, &&
  program_transform_name=s,y,y,

AC_CANONICAL_SYSTEM
AC_ARG_PROGRAM

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
