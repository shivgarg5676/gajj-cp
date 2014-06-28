#!/bin/bash
read a <shiv.txt 
git clone $a 
echo $? > shiv1.txt 
exit 
