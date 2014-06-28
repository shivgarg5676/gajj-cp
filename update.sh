#!/bin/bash
exec 0< log.txt 
read password <password.txt
delim=" "
IFS=" "
read i 
while (( $i > 0 ))
do
read a r0 r1 r2 r3 r4 r5 r6
echo $password | sudo -S update-rc.d -f $a remove
u_command="update-rc.d $a start 20"
runlevel=0
for runlevel in 0 1 2 3 4 5 6
do
t=r$runlevel
if (( $t == 1 ))
then 
u_command="$u_command $runlevel"
fi
done
u_command="$u_command ."
sudo $u_command 
let i=$i-1
done
exit
