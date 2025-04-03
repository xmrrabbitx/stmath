# stmath php ext
### Installatioon in Linux
```bash
$ cd to /yourPhpVersion path
```
```
$ git clone https://github.com/xmrrabbitx/stmath.git 
```
```bash
$ cd /stmath directory
```
```bash
$ ../bin/phpize
```
```bash
$ ./configure --with-php-config=$HOME/yourPhpVersion/bin/php-config
```
```bash
$ make -j2 number of parallel jobs/processes to run
```
```bash
$ make install
```
```bash
$ add extension to php.ini: extenstion=stmath.so
```
```bash
$ verify extension is loaded: ../bin/php -dextension=stmath -m | grep stmathsh
```

#### Example Median
```php
<?php

$median = stmathMedian([1,2,3,4]);
var_dump($median);

Result: float(2.5)
```
