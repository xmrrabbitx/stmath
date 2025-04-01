dnl config.m4 for extension stmath

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary.

dnl If your extension references something external, use 'with':

dnl PHP_ARG_WITH([stmath],
dnl   [for stmath support],
dnl   [AS_HELP_STRING([--with-stmath],
dnl     [Include stmath support])])

dnl Otherwise use 'enable':

PHP_ARG_ENABLE([stmath],
  [whether to enable stmath support],
  [AS_HELP_STRING([--enable-stmath],
    [Enable stmath support])],
  [no])

if test "$PHP_STMATH" != "no"; then
  dnl Write more examples of tests here...

  dnl Remove this code block if the library does not support pkg-config.
  dnl PKG_CHECK_MODULES([LIBFOO], [foo])
  dnl PHP_EVAL_INCLINE($LIBFOO_CFLAGS)
  dnl PHP_EVAL_LIBLINE($LIBFOO_LIBS, STMATH_SHARED_LIBADD)

  dnl If you need to check for a particular library version using PKG_CHECK_MODULES,
  dnl you can use comparison operators. For example:
  dnl PKG_CHECK_MODULES([LIBFOO], [foo >= 1.2.3])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo < 3.4])
  dnl PKG_CHECK_MODULES([LIBFOO], [foo = 1.2.3])

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-stmath -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/stmath.h"  # you most likely want to change this
  dnl if test -r $PHP_STMATH/$SEARCH_FOR; then # path given as parameter
  dnl   STMATH_DIR=$PHP_STMATH
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for stmath files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       STMATH_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$STMATH_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the stmath distribution])
  dnl fi

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-stmath -> add include path
  dnl PHP_ADD_INCLUDE($STMATH_DIR/include)

  dnl Remove this code block if the library supports pkg-config.
  dnl --with-stmath -> check for lib and symbol presence
  dnl LIBNAME=STMATH # you may want to change this
  dnl LIBSYMBOL=STMATH # you most likely want to change this

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   AC_DEFINE(HAVE_STMATH_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your stmath library.])
  dnl ], [
  dnl   $LIBFOO_LIBS
  dnl ])

  dnl If you need to check for a particular library function (e.g. a conditional
  dnl or version-dependent feature) and you are not using pkg-config:
  dnl PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $STMATH_DIR/$PHP_LIBDIR, STMATH_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_STMATH_FEATURE, 1, [ ])
  dnl ],[
  dnl   AC_MSG_ERROR([FEATURE not supported by your stmath library.])
  dnl ],[
  dnl   -L$STMATH_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(STMATH_SHARED_LIBADD)

  dnl In case of no dependencies
  AC_DEFINE(HAVE_STMATH, 1, [ Have stmath support ])

  PHP_NEW_EXTENSION(stmath, stmath.c, $ext_shared)
fi
