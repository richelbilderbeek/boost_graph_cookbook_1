#!/bin/bash

for filename in $(ls *.svg)
do
  echo $filename
  new_filename=`echo $filename | sed 's/\.svg/\.png/'`
  echo $new_filename
  convert $filename $new_filename
done
