/* stmath extension for PHP */

#ifndef PHP_STMATH_H
# define PHP_STMATH_H

extern zend_module_entry stmath_module_entry;
# define phpext_stmath_ptr &stmath_module_entry

# define PHP_STMATH_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_STMATH)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

PHP_FUNCTION(hello_world);
PHP_FUNCTION(test1);
PHP_FUNCTION(test2);

#endif	/* PHP_STMATH_H */
