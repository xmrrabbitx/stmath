/* stmath extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_stmath.h"
#include "stmath_arginfo.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

PHP_FUNCTION(stmathMedian){


	zend_array *arr;
	zend_ulong count;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "h", &arr) == FAILURE) {

		return;

	}
	
	count = zend_hash_num_elements(arr);
	RETURN_LONG(count);
}


ZEND_BEGIN_ARG_INFO(arginfo_stmathMedian, 0)
ZEND_ARG_ARRAY_INFO(0, array, 0)
ZEND_END_ARG_INFO()

/* {{{ void test1() */
PHP_FUNCTION(test1)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("The extension %s is loaded and working!\r\n", "stmath");
}
/* }}} */

/* {{{ string test2( [ string $var ] ) */
PHP_FUNCTION(test2)
{
	char *var = "World";
	size_t var_len = sizeof("World") - 1;
	zend_string *retval;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(var, var_len)
	ZEND_PARSE_PARAMETERS_END();

	retval = strpprintf(0, "Hello %s", var);

	RETURN_STR(retval);
}
/* }}}*/


/* {{{ PHP_RINIT_FUNCTION */
PHP_RINIT_FUNCTION(stmath)
{
#if defined(ZTS) && defined(COMPILE_DL_STMATH)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(stmath)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "stmath support", "enabled");
	php_info_print_table_end();
}
/* }}} */

static const zend_function_entry stmath_functions[] = {
		PHP_FE(stmathMedian,             arginfo_stmathMedian)  // Add this line
		PHP_FE(test1, arginfo_test1)
		PHP_FE(test2, arginfo_test2)
		PHP_FE_END
};


/* {{{ stmath_module_entry */
zend_module_entry stmath_module_entry = {
	STANDARD_MODULE_HEADER,
	"stmath",					/* Extension name */
	stmath_functions,					/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(stmath),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(stmath),			/* PHP_MINFO - Module info */
	PHP_STMATH_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_STMATH
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(stmath)
#endif
