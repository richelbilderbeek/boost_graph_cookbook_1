#!/bin/bash

for filename in `ls *.cpp`
do
  echo $filename
  new_filename=`echo $filename | sed 's/\.cpp/_test\.cpp/'`
  echo $new_filename
  cp $filename $new_filename
done