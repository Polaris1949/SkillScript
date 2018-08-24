binsks_builddir = `${pwd}`
case $srcdir in
    [\\/$]* | ?:[\\/]*) binsks_srcdir=${srcdir} ;;
    *) binsks_srcdir=`cd "$srcdir" && ${pwd} || echo "$srcdir"` ;;
esac

toplevel_builddir = ${binsks_builddir}/..
toplevel_srcdir = ${binsks_srcdir}/..
