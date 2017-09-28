#!/bin/bash

# Shell problems
# Word Frequency


# NOte: use newline in sed
cat words.txt | sed -E 's/ +/\
/g' | grep -v '^$' |  sort | uniq -c | sort -r |  awk '{print $2 " " $1}'


# also use tr command

cat words.txt | tr -s ' ' '\n' | sort | uniq -c | same as above code    
