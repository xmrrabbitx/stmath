# stmath php ext
### Installatioon in Linux
#### $ cd to /yourPhpVersion path
#### $ git clone https://github.com/xmrrabbitx/stmath.git 
#### $ cd stmath directory
#### $ ../bin/phpize
#### $ ./configure --with-php-config=$HOME/yourPhpVersion/bin/php-config
#### $ make -j2 number of parallel jobs/processes to run
#### $ make install
#### $ add extension to php.ini: extenstion=stmath.so
#### $ verify extension is loaded: ../bin/php -dextension=stmath -m | grep stmath
