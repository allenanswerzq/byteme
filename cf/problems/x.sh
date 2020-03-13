#!/bin/bash
line=unharmed

# Synchronization "flags"
sync1=`mktemp`
sync2=`mktemp`

( while read line ; do
    echo "$line" | grep 'aaa' 1>&100
    echo "$line" | grep 'bbb' 1>&101
  done;
) \
100> >( while read line ; do echo "$line" | sed -e 's/x/y/g'; sleep 1 ; done; rm $sync1 ) \
101> >( while read line ; do echo "$line" | sed -e 's/x/z/g'; sleep 2 ; done; rm $sync2 ) \
   < <( for ((i=0;i<6;i++)) ; do echo aaaxxx; echo bbbxxx ; done; echo ooops )

# "Synchronize" subprocesses
while [ -f "$sync1" ] ; do sleep 1 ; done
while [ -f "$sync2" ] ; do sleep 1 ; done

echo "The $line is unharmed : $line"
# Since all above are subshells, there won't be any effect on $line variable:
#    The $line is unharmed : unharmed
