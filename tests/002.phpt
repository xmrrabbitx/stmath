--TEST--
test1() Basic test
--EXTENSIONS--
stmath
--FILE--
<?php
$ret = test1();

var_dump($ret);
?>
--EXPECT--
The extension stmath is loaded and working!
NULL
