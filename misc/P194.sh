#!/bin/bash

num=$(head -n 1 file.txt|wc -w)
for (( i=1; i<=$num; i++ ))
do
    # NOte: difference ouput between `cat file.txt` and var=`cat file.txt`
    # last one stretchs whole content into a one line and remove the endings each lines
    cols=`cat file.txt | awk "{print $"$i"}"`;
    echo $cols
done
