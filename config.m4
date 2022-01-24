
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

use_bundled_ionc=false
AC_DEFUN([ION_BUNDLE], [dnl

  sdir=PHP_EXT_SRCDIR([ion])
  AC_MSG_CHECKING([for bundled ion-c])
  if test -f $sdir/ion-c/CMakeLists.txt; then
    AC_MSG_RESULT([ion-c])
  elif test -d $sdir/.git; then
    AC_MSG_RESULT([git submodule])
    cd $sdir
    if ! "$GIT" submodule update --init --depth 1 --recursive ion-c; then
      cd -
      AC_MSG_ERROR([giving up on path "$sdir"])
    fi
    cd -
  elif "$GIT" clone -q --depth 1 --recursive https://github.com/amzn/ion-c $sdir/ion-c; then
    AC_MSG_RESULT([git clone])
  else
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([invalid bundle: $sdir/ion-c])
  fi

  PHP_ADD_INCLUDE(PHP_EXT_SRCDIR([ion])/ion-c/ionc/include)
  PHP_ADD_INCLUDE(PHP_EXT_SRCDIR([ion])/ion-c/decNumber/include)

  PHP_EXPAND_PATH(PHP_EXT_BUILDDIR([ion]), bdir)
  bdir="$bdir/ion-c/build"
  if test "$ext_shared" = yes; then
    ION_SHARED_LIBADD="-lionc_static -ldecNumber_static -L$bdir/ionc -L$bdir/decNumber"
  else
    DLIBS="$DLIBS -lionc_static -ldecNumber_static"
    EXTRA_LDFLAGS="$EXTRA_LDFLAGS -L$bdir/ionc -L$bdir/decNumber"
    EXTRA_LDFLAGS_PROGRAM="$EXTRA_LDFLAGS_PROGRAM -L$bdir/ionc -L$bdir/decNumber"
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
