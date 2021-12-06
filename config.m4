
PHP_ARG_WITH([ion],
  [for ion support],
  [AS_HELP_STRING([--with-ion],
    [path to libion])],
  [no])

if test "$PHP_ION" != "no"; then

  SEARCH_PATH="/usr/local /usr"     # you might want to change this
  SEARCH_FOR="/include/ionc/ion.h"  # you most likely want to change this
  if test -r $PHP_ION/$SEARCH_FOR; then # path given as parameter
    ION_DIR=$PHP_ION
  else # search default path list
    AC_MSG_CHECKING([for ion files in default path])
    for i in $SEARCH_PATH ; do
      if test -r $i/$SEARCH_FOR; then
        ION_DIR=$i
        AC_MSG_RESULT(found in $i)
      fi
    done
  fi
  dnl
  if test -z "$ION_DIR"; then
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([Please reinstall the ion distribution])
  fi

  PHP_ADD_INCLUDE($ION_DIR/include)

  LIBNAME=ionc
  LIBSYMBOL=ion_error_to_str
  PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  [
    PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $ION_DIR/$PHP_LIBDIR, ION_SHARED_LIBADD)
  ],[
    AC_MSG_ERROR([could not link with ionc library.])
  ],[
    -L$ION_DIR/$PHP_LIBDIR -lm
  ])
  LIBNAME=decNumber
  LIBSYMBOL=decQuadFromInt32
  PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  [
    PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $ION_DIR/$PHP_LIBDIR, ION_SHARED_LIBADD)
  ],[
    AC_MSG_ERROR([could not link with ionc library.])
  ],[
    -L$ION_DIR/$PHP_LIBDIR -lm
  ])

  PHP_SUBST(ION_SHARED_LIBADD)
  AC_DEFINE(HAVE_ION, 1, [ Have ion support ])

  PHP_NEW_EXTENSION(ion, ion.c, $ext_shared)
fi
