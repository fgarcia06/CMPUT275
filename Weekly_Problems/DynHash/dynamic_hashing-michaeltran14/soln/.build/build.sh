#!/bin/bash
NAME=we4_solution
if ! [ -f $NAME ]
then
    make -s $NAME
    rm *.o
fi
chmod +x $NAME
./$NAME
rm -f $NAME
