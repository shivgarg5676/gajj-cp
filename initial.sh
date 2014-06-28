#!/bin/bash
r=`ls /etc/init.d/`
echo `ls /etc/init.d/ | wc -w` >log.txt
runlevel0=0
runlevel1=0
runlevel2=0
runlevel3=0
runlevel4=0
runlevel5=0
runlevel6=0
for s in $r
do 
for i in 0 1 2 3 4 5 6 
do
if [ -e /etc/rc$i.d/???$s ]
then 
let runlevel$i=1
else 
let runlevel$i=0
fi
done
t=`cat resticted_services.txt | grep $s`
if [ -z "$t" ]
then
echo $s $runlevel0 $runlevel1 $runlevel2 $runlevel3 $runlevel4 $runlevel5 $runlevel6 >> log.txt 
fi
done
