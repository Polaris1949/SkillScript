#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libsks], [1.1.0], [BeiChen1949@gmail.com])
AC_CONFIG_SRCDIR([src/version.cc])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([..])
AM_INIT_AUTOMAKE([1.15.1 no-define foreign no-dependencies no-dist -Wall -Wno-portability -Wno-override])
AH_TEMPLATE(PACKAGE, [Name of package])
AH_TEMPLATE(VERSION, [Version number of package])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Libtool setup.
AC_PROG_LIBTOOL
AC_CONFIG_MACRO_DIRS([..])
LT_INIT
AM_ENABLE_STATIC
AM_ENABLE_SHARED

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
