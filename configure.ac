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

# Record and document user additions to sub configure arguments.
AC_ARG_VAR([build_configargs],
	   [additional configure arguments for build directories])
AC_ARG_VAR([host_configargs],
	   [additional configure arguments for host directories])
AC_ARG_VAR([target_configargs],
	   [additional configure arguments for target directories])

build_configargs="$build_configargs ${baseargs}"
host_configargs="$host_configargs ${baseargs}"
target_configargs="$target_configargs ${baseargs}"

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

# Build module lists & subconfigure args.
AC_SUBST(build_configargs)
AC_SUBST(build_configdirs)

# Host module lists & subconfigure args.
AC_SUBST(host_configargs)
AC_SUBST(configdirs)
AC_SUBST(target_configdirs)

# Target module lists & subconfigure args.
AC_SUBST(target_configargs)

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
