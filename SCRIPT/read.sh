#!/bin/sh

echo "Enter two number"
read a b 
c=`expr $a + $b`
echo "Sum = $c" 

DATE=`date`
echo "Date is $DATE"
