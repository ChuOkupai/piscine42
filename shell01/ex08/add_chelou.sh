#!/bin/sh
n1=`echo $FT_NBR1 | sed 'y/'\''\\"?!/01234/'`
n2=`echo $FT_NBR2 | sed 'y/mrdoc/01234/'`
b5=`echo "ibase=5;$n1+$n2" | bc`
echo "obase=13;$b5" | bc | sed 'y/0123456789ABC/gtaio luSnemf/'
