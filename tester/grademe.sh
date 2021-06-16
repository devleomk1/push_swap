#!/bin/bash

echo -n "number: "
read NUM
gcc test.c
./a.out $NUM > abc
make re -C ../
EE=`cat abc`
.././push_swap $EE > result.txt
echo -n 'number of result ='
wc -l < result.txt
./checker_Mac `cat abc` < result.txt