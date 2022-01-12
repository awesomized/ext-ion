
PHP_ARG_WITH([ion],
  [for ION support],
  [AS_HELP_STRING([--with-ion],
    [path to libion])],
  [no])

AC_ARG_VAR([GIT], [git executable])
AC_PATH_PROG([GIT], [git])
PHP_SUBST([GIT])

AC_ARG_VAR([CMAKE], [cmake executable])
AC_PATH_PROG([CMAKE], [cmake])
PHP_SUBST([CMAKE])

AC_ARG_VAR([AR], [system library archiver])
AC_PATH_PROG([AR], [ar])
PHP_SUBST([AR])

AC_ARG_VAR([RANLIB], [system library archive indexer])
AC_PATH_PROG([RANLIB], [ranlib])
PHP_SUBST([RANLIB])

use_bundled_ionc=false
AC_DEFUN([ION_BUNDLE], [dnl

  AC_MSG_CHECKING([for bundled ion-c])
  if test -f PHP_EXT_SRCDIR([ion])/ion-c/CMakeLists.txt; then
    AC_MSG_RESULT([ion-c])
  elif test -d PHP_EXT_SRCDIR([ion])/.git; then
    AC_MSG_RESULT([git submodule])
    if ! GIT_DIR=PHP_EXT_SRCDIR([ion])/.git GIT_WORK_TREE=PHP_EXT_SRCDIR([ion])/ \
        "$GIT" submodule update --init --depth 1 --recursive ion-c; then
      AC_MSG_ERROR([giving up])
    fi
  else
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([invalid bundle: PHP_EXT_SRCDIR([ion])/ion-c])
  fi

  PHP_ADD_INCLUDE(PHP_EXT_SRCDIR([ion])/ion-c/ionc/include)
  PHP_ADD_INCLUDE(PHP_EXT_SRCDIR([ion])/ion-c/decNumber/include)

  PHP_EXPAND_PATH(PHP_EXT_BUILDDIR([ion]), builddir)
  builddir="$builddir/ion-c/build"
  if test "$ext_shared" = yes; then
    ION_SHARED_LIBADD="-lionc_static -ldecNumber_static -L$builddir/ionc -L$builddir/decNumber"
  else
    DLIBS="$DLIBS -lionc_static -ldecNumber_static"
    EXTRA_LDFLAGS="$EXTRA_LDFLAGS -L$builddir/ionc -L$builddir/decNumber"
    EXTRA_LDFLAGS_PROGRAM="$EXTRA_LDFLAGS_PROGRAM -L$builddir/ionc -L$builddir/decNumber"
  fi

  if test "$PHP_DEBUG" = 1; then
    LIB_IONC_BUILD=Debug
  else
    LIB_IONC_BUILD=Release
  fi
  PHP_SUBST(LIB_IONC_BUILD)
  PHP_ADD_MAKEFILE_FRAGMENT()
])
AC_DEFUN([ION_CHECK_LIB], [dnl
  LIBNAME=$1
  LIBSYMBOL=$2
  PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  [
    [have_]AS_TR_SH($LIBNAME)[_]AS_TR_SH($LIBSYMBOL)=true
    AC_DEFINE([HAVE_]AS_TR_CPP($LIBNAME)[_]AS_TR_CPP($LIBSYMBOL), 1, [ ])
    PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $ION_DIR/$PHP_LIBDIR, ION_SHARED_LIBADD)
  ],[
    [have_]AS_TR_SH($LIBNAME)[_]AS_TR_SH($LIBSYMBOL)=true
    AC_MSG_WARN([could not link with $LIBNAME library or find $LIBSYMBOL.])
  ],[
    -L$ION_DIR/$PHP_LIBDIR -lm
  ])
])
AC_DEFUN([ION_SYSTEM], [dnl
    SEARCH_PATH="/usr/local /usr"
    SEARCH_FOR="/include/ionc/ion.h"
    if test -r $PHP_ION/$SEARCH_FOR; then
      ION_DIR=$PHP_ION
    else
      AC_MSG_CHECKING([for ion-c files in default path])
      for i in $SEARCH_PATH ; do
        if test -r $i/$SEARCH_FOR; then
          ION_DIR=$i
          break
        fi
      done
    fi
    dnl
    if test -n "$ION_DIR"; then
      AC_MSG_RESULT(found in $ION_DIR)
      PHP_ADD_INCLUDE([$ION_DIR/include])
      ION_CHECK_LIB(ionc, ion_error_to_str)
      ION_CHECK_LIB(decNumber, decQuadFromInt32)
      if ! $have_ionc_ion_error_to_str || ! $have_decNumber_decQuadFromInt32; then
        ION_BUNDLE
      fi
    else
      AC_MSG_RESULT([not found])
      ION_BUNDLE
    fi

])

if test "$PHP_ION" != "no"; then
  PHP_NEW_EXTENSION(ion, ion.c, $ext_shared)

  case "$PHP_ION" in
  ion-c|b|bundle*)  ION_BUNDLE  ;;
  *)                ION_SYSTEM  ;;
  esac

  PHP_SUBST(ION_SHARED_LIBADD)
  AC_DEFINE(HAVE_ION, 1, [ Have ion support ])
fi
