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


// Comparison function for qsort
static int compare_doubles(const void *a, const void *b) {

	double arg1 = *(const double*)a;
	double arg2 = *(const double*)b;

	if (arg1 < arg2) return -1;
	if (arg1 > arg2) return 1;
	return 0;
}


PHP_FUNCTION(stmathMedian){


	zend_array *arr;
	double *values = NULL;
	zend_ulong count;
	zval *val;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "h", &arr) == FAILURE) {

		return;

	}
	
	count = zend_hash_num_elements(arr);
	if (count == 0) {
        	RETURN_NULL();
    	}
	
	// Allocate memory for values
	values = emalloc(count * sizeof(double));
	if (!values) {
		php_error_docref(NULL, E_WARNING, "Memory allocation failed");
		RETURN_NULL();
	}

	// Copy numeric values to our double array
	zend_ulong i = 0;
	ZEND_HASH_FOREACH_VAL(arr,val){
		// Convert to double if numeric
		if (Z_TYPE_P(val) == IS_LONG) {
			values[i++] = (double)Z_LVAL_P(val);
		}
		else if(Z_TYPE_P(val) == IS_DOUBLE) {
			values[i++] = (double)Z_DVAL_P(val);

		}else{

			// Skip non-numeric values (reduce count)
			count--;
		
		}
			
	} ZEND_HASH_FOREACH_END();
	
	// Check if we have any values left
	if(count==0){

		efree(values);
		php_error_docref(NULL, E_WARNING, "Array contains no numeric values");
		RETURN_NULL();
	}

	// Sort the values
	qsort(values, count, sizeof(double), compare_doubles);
	

	// Calculate median
	if (count % 2 == 0) {
		// Even number of elements - average of middle two
		double median = (values[(count/2) -1] + values[count/2]) / 2.0;
		RETURN_DOUBLE(median);
	}else{
		// Odd number of elements - middle element
		RETURN_DOUBLE(values[count/2]);
	}

	// Free memory
	efree(values);
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
