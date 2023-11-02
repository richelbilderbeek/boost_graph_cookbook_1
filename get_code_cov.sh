#!/bin/bash

for filename in $(find . | grep -E '\.cpp$')
do 
  gcov -n -o . "${filename}" > /dev/null
done
