#!/usr/bin/bash

##cd into the directory by the given path
cd $1

##Using find, to find all of the type files, and then using | and wc -l to count the number of lines of
##the output for find . -type f, and lastly,
##we use xargs to get rid of any white space
echo "There were `find . -type d | wc -l | xargs` directories."

##Using find, to find all of the type dirctories, and then using | and wc -l to count the number of lines of
##the output for find . -type f, and lastly,
##we use xargs to get rid of any white space
echo "There were `find . -type f | wc -l | xargs` regular files."
