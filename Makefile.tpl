[+ AutoGen5 template -*- Mode: Makefile -*-
in
+]

# Makefile.in is generated from Makefile.tpl by 'autogen Makefile.def'.
#
# Makefile for directory with subdirs to build.
#   Copyright (C) 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998,
#   1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011
#   Free Software Foundation
#
# This file is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; see the file COPYING3.  If not see
# <http://www.gnu.org/licenses/>.
#

# First, test for a proper version of make, but only where one is required.

ifeq (,$(.VARIABLES)) # The variable .VARIABLES, new with 3.80, is never empty.
$(error GNU make version 3.80 or newer is required.)
endif

# -------------------------------
# Standard Autoconf-set variables
# -------------------------------
VPATH=@srcdir@

build_alias=@build_noncanonical@
build_vendor=@build_vendor@
build_os=@build_os@
build=@build@
host_alias=@host_noncanonical@
host_vendor=@host_vendor@
host_os=@host_os@
host=@host@
target_alias=@target_noncanonical@
target_vendor=@target_vendor@
target_os=@target_os@
target=@target@

program_transform_name = @program_transform_name@

prefix = @prefix@
exec_prefix = @exec_prefix@

srcdir = @srcdir@

bindir = @bindir@
sbindir = @sbindir@
libexecdir = @libexecdir@
datadir = @datadir@
sysconfdir = @sysconfdir@
sharedstatedir = @sharedstatedir@
localstatedir = @localstatedir@
libdir = @libdir@
includedir = @includedir@
oldincludedir = @oldincludedir@
infodir = @infodir@
datarootdir = @datarootdir@
docdir = @docdir@
pdfdir = @pdfdir@
htmldir = @htmldir@
mandir = @mandir@
man1dir = $(mandir)/man1
man2dir = $(mandir)/man2
man3dir = $(mandir)/man3
man4dir = $(mandir)/man4
man5dir = $(mandir)/man5
man6dir = $(mandir)/man6
man7dir = $(mandir)/man7
man8dir = $(mandir)/man8
man9dir = $(mandir)/man9

INSTALL = @INSTALL@
INSTALL_PROGRAM = @INSTALL_PROGRAM@
INSTALL_SCRIPT = @INSTALL_SCRIPT@
INSTALL_DATA = @INSTALL_DATA@
LN = @LN@
LN_S = @LN_S@
MAINT = @MAINT@
MAINTAINER_MODE_FALSE = @MAINTAINER_MODE_FALSE@
MAINTAINER_MODE_TRUE = @MAINTAINER_MODE_TRUE@

# -------------------------------------------------
# Miscellaneous non-standard autoconf-set variables
# -------------------------------------------------

# The gcc driver likes to know the arguments it was configured with.
TOPLEVEL_CONFIGURE_ARGUMENTS=@TOPLEVEL_CONFIGURE_ARGUMENTS@

tooldir = @tooldir@
build_tooldir = @build_tooldir@

# This is the name of the environment variable used for the path to
# the libraries.
RPATH_ENVVAR = @RPATH_ENVVAR@

# Build programs are put under this directory.
BUILD_SUBDIR = @build_subdir@
# This is set by the configure script to the arguments to use when configuring
# directories built for the build system.
BUILD_CONFIGARGS = @build_configargs@ --with-build-subdir="$(BUILD_SUBDIR)"

# ----------------------------------------------
# Programs producing files for the BUILD machine
# ----------------------------------------------

SHELL = @SHELL@

# pwd command to use.  Allow user to override default by setting PWDCMD in
# the environment to account for automounters.  The make variable must not
# be called PWDCMD, otherwise the value set here is passed to make
# subprocesses and overrides the setting from the user's environment.
# Don't use PWD since it is a common shell environment variable and we
# don't want to corrupt it.
PWD_COMMAND = $${PWDCMD-pwd}

AWK = @AWK@
SED = @SED@
BISON = @BISON@
YACC = @YACC@
FLEX = @FLEX@
LEX = @LEX@
M4 = @M4@
MAKEINFO = @MAKEINFO@
EXPECT = @EXPECT@
RUNTEST = @RUNTEST@

# ---------------------------------------------
# Programs producing files for the HOST machine
# ---------------------------------------------

AS = @AS@
AR = @AR@
AR_FLAGS = rc
CC = @CC@
CXX = @CXX@
DLLTOOL = @DLLTOOL@
LD = @LD@
LIPO = @LIPO@
NM = @NM@
OBJDUMP = @OBJDUMP@
RANLIB = @RANLIB@
READELF = @READELF@
STRIP = @STRIP@
WINDRES = @WINDRES@
WINDMC = @WINDMC@

GNATBIND = @GNATBIND@
GNATMAKE = @GNATMAKE@

CFLAGS = @CFLAGS@
LDFLAGS = @LDFLAGS@
LIBCFLAGS = $(CFLAGS)
CXXFLAGS = @CXXFLAGS@
LIBCXXFLAGS = $(CXXFLAGS) -fno-implicit-templates
GOCFLAGS = $(CFLAGS)

CREATE_GCOV = create_gcov

TFLAGS =


# ------------------------------------
# Macros for configure and all targets
# ------------------------------------

[+ DEFINE configure +]
.PHONY: configure-[+prefix+][+module+] maybe-configure-[+prefix+][+module+]
maybe-configure-[+prefix+][+module+]:


maybe-configure-[+prefix+][+module+]: configure-[+prefix+][+module+]
configure-[+prefix+][+module+]: [+ IF bootstrap +][+ ELSE +]
	@: $(MAKE); $(unstage)[+ ENDIF bootstrap +]
	@r=`${PWD_COMMAND}`; export r; \
	s=`cd $(srcdir); ${PWD_COMMAND}`; export s; \
	test ! -f [+module+]/Makefile || exit 0; \
	$(SHELL) $(srcdir)/mkinstalldirs [+module+]; \
	[+exports+] [+extra_exports+] \
	echo Configuring in [+module+]; \
	cd "[+module+]" || exit 1; \
	case $(srcdir) in \
	  /* | [A-Za-z]:[\\/]*) topdir=$(srcdir) ;; \
	  *) topdir=`echo [+module+]/ | \
		sed -e 's,\./,,g' -e 's,[^/]*/,../,g' `$(srcdir) ;; \
	esac; \
	module_srcdir=[+? module_srcdir (get "module_srcdir") (get "module")+]; \
	[+ IF no-config-site +]rm -f no-such-file || : ; \
	CONFIG_SITE=no-such-file [+ ENDIF +]$(SHELL) \
	  $$s/$$module_srcdir/configure \
	  --srcdir=$${topdir}/$$module_srcdir \
	  [+args+] --build=${build_alias} --host=[+host_alias+] \
	  --target=[+target_alias+] [+extra_configure_flags+] \
	  || exit 1

[+ ENDDEF +]

[+ DEFINE all +]
.PHONY: all-[+prefix+][+module+] maybe-all-[+prefix+][+module+]
maybe-all-[+prefix+][+module+]:

TARGET-[+prefix+][+module+]=[+
  IF all_target +][+all_target+][+ ELSE +]all[+ ENDIF all_target +]
maybe-all-[+prefix+][+module+]: all-[+prefix+][+module+]
all-[+prefix+][+module+]: configure-[+prefix+][+module+][+ IF bootstrap +][+ ELSE +]
	@: $(MAKE); $(unstage)[+ ENDIF bootstrap +]
	@r=`${PWD_COMMAND}`; export r; \
	s=`cd $(srcdir); ${PWD_COMMAND}`; export s; \
	[+exports+] [+extra_exports+] \
	(cd [+module+] && \
	  $(MAKE) $(BASE_FLAGS_TO_PASS) [+args+] [+stage1_args+] [+extra_make_flags+] \
		$(TARGET-[+prefix+][+module+]))

[+ ENDDEF +]

# ------------------------------------
# Miscellaneous targets and flag lists
# ------------------------------------

# The first rule in the file had better be this one.  Don't put any above it.
# This lives here to allow makefile fragments to contain dependencies.
all:

# This is the list of directories that may be needed in RPATH_ENVVAR
# so that programs built for the target machine work.
TARGET_LIB_PATH = [+ FOR target_modules +][+
  IF lib_path +]$(TARGET_LIB_PATH_[+module+])[+ ENDIF lib_path +][+
  ENDFOR target_modules +]$(HOST_LIB_PATH_gcc)
[+ FOR target_modules +][+ IF lib_path +]

TARGET_LIB_PATH_[+module+] = $$r/[+module+]/[+lib_path+]:

[+ ENDIF lib_path +][+ ENDFOR target_modules +]

.PHONY: configure-target
configure-target: [+
  FOR target_modules +] \
    maybe-configure-target-[+module+][+
  ENDFOR target_modules +]

# The target built for a native non-bootstrap build.
.PHONY: all
all:
	@: $(MAKE);
	@r=`${PWD_COMMAND}`; export r; \
	s=`cd $(srcdir); ${PWD_COMMAND}`; export s; \
	  $(MAKE) $(RECURSE_FLAGS_TO_PASS) all-target \
	&& :

.PHONY: all-target
[+ FOR target_modules +]
all-target: maybe-all-target-[+module+][+ ENDFOR target_modules +]

# Do a target for all the subdirectories.  A ``make do-X'' will do a
# ``make X'' in all subdirectories (because, in general, there is a
# dependency (below) of X upon do-X, a ``make X'' will also do this,
# but it may do additional work as well).
[+ FOR recursive_targets +]
.PHONY: do-[+make_target+]
do-[+make_target+]:
	@: $(MAKE); $(unstage)
	@r=`${PWD_COMMAND}`; export r; \
	s=`cd $(srcdir); ${PWD_COMMAND}`; export s; \
	$(MAKE) $(RECURSE_FLAGS_TO_PASS)  \
	  [+make_target+]-target

.PHONY: [+make_target+]-target
[+ FOR target_modules +]
[+make_target+]-target: maybe-[+make_target+]-target-[+module+][+ ENDFOR target_modules +]
[+ ENDFOR recursive_targets +]

# Here are the targets which correspond to the do-X targets.

.PHONY: info installcheck dvi pdf html
.PHONY: install-info install-pdf install-html
.PHONY: clean distclean mostlyclean maintainer-clean realclean
.PHONY: local-clean local-distclean local-maintainer-clean
info: do-info
installcheck: do-installcheck
dvi: do-dvi
pdf: do-pdf
html: do-html

# Make sure makeinfo is built before we do a `make info', if we're
# in fact building texinfo.
do-info: maybe-all-texinfo

install-info: do-install-info dir.info
	s=`cd $(srcdir); ${PWD_COMMAND}`; export s; \
	if [ -f dir.info ]; then \
	  $(INSTALL_DATA) dir.info $(DESTDIR)$(infodir)/dir.info; \
	else true; fi

install-pdf: do-install-pdf

install-html: do-install-html

local-clean:
	-rm -f *.a TEMP errs core *.o *~ \#* TAGS *.E *.log

local-distclean:
	-rm -f Makefile config.status config.cache mh-frag mt-frag
	-rm -f maybedep.tmp serdep.tmp stage_final
	-if [ "$(TARGET_SUBDIR)" != "." ]; then \
	  rm -rf $(TARGET_SUBDIR); \
	else true; fi
	-rm -rf $(BUILD_SUBDIR)
	-if [ "$(HOST_SUBDIR)" != "." ]; then \
	  rm -rf $(HOST_SUBDIR); \
	else true; fi
	-rm -f texinfo/po/Makefile texinfo/po/Makefile.in texinfo/info/Makefile
	-rm -f texinfo/doc/Makefile texinfo/po/POTFILES
	-rmdir texinfo/doc texinfo/info texinfo/intl texinfo/lib 2>/dev/null
	-rmdir texinfo/makeinfo texinfo/po texinfo/util 2>/dev/null
	-rmdir fastjar gcc gnattools gotools libcc1 libiberty 2>/dev/null
	-rmdir texinfo zlib 2>/dev/null
	-find . -name config.cache -exec rm -f {} \; \; 2>/dev/null

local-maintainer-clean:
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."

clean: do-clean local-clean
mostlyclean: do-mostlyclean local-clean
distclean: do-distclean local-clean local-distclean
maintainer-clean: local-maintainer-clean do-maintainer-clean local-clean
maintainer-clean: local-distclean
realclean: maintainer-clean


# ---------------------------------------
# Modules which run on the target machine
# ---------------------------------------
[+ FOR target_modules +]

[+ IF raw_cxx +]
[+ configure prefix="target-" subdir="$(TARGET_SUBDIR)"
	     check_multilibs=false
	     exports="$(RAW_CXX_TARGET_EXPORTS)"
	     host_alias=(get "host" "${target_alias}")
	     target_alias=(get "target" "${target_alias}")
	     args="$(TARGET_CONFIGARGS)" no-config-site=true +]

[+ all prefix="target-" subdir="$(TARGET_SUBDIR)"
       exports="$(RAW_CXX_TARGET_EXPORTS)"
       args="$(EXTRA_TARGET_FLAGS) 'CXX=$$(RAW_CXX_FOR_TARGET)' 'CXX_FOR_TARGET=$$(RAW_CXX_FOR_TARGET)'" +]
[+ ELSE +]
[+ configure prefix="target-" subdir="$(TARGET_SUBDIR)"
	     check_multilibs=false
	     exports="$(NORMAL_TARGET_EXPORTS)"
	     host_alias=(get "host" "${target_alias}")
	     target_alias=(get "target" "${target_alias}")
	     args="$(TARGET_CONFIGARGS)" no-config-site=true +]

[+ all prefix="target-" subdir="$(TARGET_SUBDIR)"
       exports="$(NORMAL_TARGET_EXPORTS)"
       args="$(EXTRA_TARGET_FLAGS)" +]
[+ ENDIF +]

.PHONY: check-target-[+module+] maybe-check-target-[+module+]
maybe-check-target-[+module+]:

maybe-check-target-[+module+]: check-target-[+module+]
[+ IF no_check +]
# Dummy target for uncheckable module.
check-target-[+module+]:
[+ ELSE check +]
check-target-[+module+]:
	@: $(MAKE); $(unstage)
	@r=`${PWD_COMMAND}`; export r; \
	s=`cd $(srcdir); ${PWD_COMMAND}`; export s; \[+
IF raw_cxx +]
	$(RAW_CXX_TARGET_EXPORTS) \[+
ELSE normal_cxx +]
	$(NORMAL_TARGET_EXPORTS) \[+
ENDIF raw_cxx +]
	(cd [+module+] && \
	  $(MAKE) $(TARGET_FLAGS_TO_PASS) [+
	    IF raw_cxx
	      +] 'CXX=$$(RAW_CXX_FOR_TARGET)' 'CXX_FOR_TARGET=$$(RAW_CXX_FOR_TARGET)' [+
	    ENDIF raw_cxx
	  +] [+extra_make_flags+] check)
[+ ENDIF no_check +]


.PHONY: install-target-[+module+] maybe-install-target-[+module+]
maybe-install-target-[+module+]:

maybe-install-target-[+module+]: install-target-[+module+]
[+ IF no_install +]
# Dummy target for uninstallable.
install-target-[+module+]:
[+ ELSE install +]
install-target-[+module+]: installdirs
	@: $(MAKE); $(unstage)
	@r=`${PWD_COMMAND}`; export r; \
	s=`cd $(srcdir); ${PWD_COMMAND}`; export s; \[+
IF raw_cxx +]
	$(RAW_CXX_TARGET_EXPORTS) \[+
ELSE normal_cxx +]
	$(NORMAL_TARGET_EXPORTS) \[+
ENDIF raw_cxx +]
	(cd [+module+] && \
	  $(MAKE) $(TARGET_FLAGS_TO_PASS) [+extra_make_flags+] install)
[+ ENDIF no_install +]


.PHONY: install-strip-target-[+module+] maybe-install-strip-target-[+module+]
maybe-install-strip-target-[+module+]:

maybe-install-strip-target-[+module+]: install-strip-target-[+module+]
[+ IF no_install +]
# Dummy target for uninstallable.
install-strip-target-[+module+]:
[+ ELSE install +]
install-strip-target-[+module+]: installdirs
	@: $(MAKE); $(unstage)
	@r=`${PWD_COMMAND}`; export r; \
	s=`cd $(srcdir); ${PWD_COMMAND}`; export s; \[+
IF raw_cxx +]
	$(RAW_CXX_TARGET_EXPORTS) \[+
ELSE normal_cxx +]
	$(NORMAL_TARGET_EXPORTS) \[+
ENDIF raw_cxx +]
	(cd [+module+] && \
	  $(MAKE) $(TARGET_FLAGS_TO_PASS) [+extra_make_flags+] install-strip)
[+ ENDIF no_install +]


# Other targets (info, dvi, pdf, etc.)
[+ FOR recursive_targets +]
.PHONY: maybe-[+make_target+]-target-[+module+] [+make_target+]-target-[+module+]
maybe-[+make_target+]-target-[+module+]:

maybe-[+make_target+]-target-[+module+]: [+make_target+]-target-[+module+]
[+ IF (match-value? = "missing" (get "make_target") ) +]
# [+module+] doesn't support [+make_target+].
[+make_target+]-target-[+module+]:
[+ ELSE +]
[+make_target+]-target-[+module+]: [+
  FOR depend +]\
    [+depend+]-target-[+module+] [+
  ENDFOR depend +]
	@: $(MAKE); $(unstage)
	@[ -f [+module+]/Makefile ] || exit 0; \
	r=`${PWD_COMMAND}`; export r; \
	s=`cd $(srcdir); ${PWD_COMMAND}`; export s; \[+
IF raw_cxx +]
	$(RAW_CXX_TARGET_EXPORTS) \[+
ELSE normal_cxx +]
	$(NORMAL_TARGET_EXPORTS) \[+
ENDIF raw_cxx +]
	echo "Doing [+make_target+] in [+module+]"; \
	for flag in $(EXTRA_TARGET_FLAGS); do \
	  eval `echo "$$flag" | sed -e "s|^\([^=]*\)=\(.*\)|\1='\2'; export \1|"`; \
	done; \
	(cd [+module+] && \
	  $(MAKE) $(BASE_FLAGS_TO_PASS) "AR=$${AR}" "AS=$${AS}" \
	          "CC=$${CC}" "CXX=$${CXX}" "LD=$${LD}" "NM=$${NM}" \
	          "RANLIB=$${RANLIB}" \
	          "DLLTOOL=$${DLLTOOL}" "WINDRES=$${WINDRES}" "WINDMC=$${WINDMC}" \
	          [+extra_make_flags+] [+make_target+]) \
	  || exit 1
[+ ENDIF +]

[+ ENDFOR recursive_targets +]
[+ ENDFOR target_modules +]

# Check target.

.PHONY: check do-check
check: do-check

# Only include modules actually being configured and built.
.PHONY: check-target
check-target: [+
  FOR target_modules +] \
    maybe-check-target-[+module+][+
  ENDFOR target_modules +]

do-check:
	@: $(MAKE); $(unstage)
	@r=`${PWD_COMMAND}`; export r; \
	s=`cd $(srcdir); ${PWD_COMMAND}`; export s; \
	$(MAKE) $(RECURSE_FLAGS_TO_PASS) check-target

# Installation targets.

.PHONY: install uninstall
install:
	@: $(MAKE); $(unstage)
	@r=`${PWD_COMMAND}`; export r; \
	s=`cd $(srcdir); ${PWD_COMMAND}`; export s; \
	$(MAKE) $(RECURSE_FLAGS_TO_PASS) installdirs install-target

.PHONY: install-target
install-target: [+
  FOR target_modules +] \
    maybe-install-target-[+module+][+
  ENDFOR target_modules +]

uninstall:
	@echo "the uninstall target is not supported in this tree"

### other supporting targets

MAKEDIRS= \
	$(DESTDIR)$(prefix) \
	$(DESTDIR)$(exec_prefix)
.PHONY: installdirs
installdirs: mkinstalldirs
	$(SHELL) $(srcdir)/mkinstalldirs $(MAKEDIRS)

# ------------------------------
# Special directives to GNU Make
# ------------------------------

# Don't pass command-line variables to submakes.
.NOEXPORT:
MAKEOVERRIDES=

# end of Makefile.in
