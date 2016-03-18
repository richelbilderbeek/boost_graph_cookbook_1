#!/bin/bash

for filename in `ls *_demo.impl`
do
  echo $filename
  new_filename=`echo $filename | sed 's/_demo/_test/'`
  echo $new_filename
  cp $filename $new_filename
done