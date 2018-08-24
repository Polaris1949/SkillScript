libsks_builddir = `${pwd}`
case $srcdir in
    [\\/$]* | ?:[\\/]*) libsks_srcdir=${srcdir} ;;
    *) libsks_srcdir=`cd "$srcdir" && ${pwd} || echo "$srcdir"` ;;
esac

toplevel_builddir = ${libsks_builddir}/..
toplevel_srcdir = ${libsks_srcdir}/..
