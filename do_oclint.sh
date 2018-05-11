#!/bin/bash

cpp_files=`find . | egrep "^\./boost_graph_cookbook_1/.*\.cpp$"| egrep -v "_test\.cpp$"`
h_files=`find . | egrep "^\./boost_graph_cookbook_1/.*_.*\.h$"`

./oclint-0.10.3/bin/oclint -o oclint.log \
  -disable-rule ShortVariableName \
  $cpp_files \
  $h_files \
  -- \
  -std=c++11 \
  -I/boost_graph_cookbook_1 \
  -I/usr/include/c++/5 \
  -I/usr/include/x86_64-linux-gnu/c++/5

cat oclint.log

# Will be 0 if success
# Will be 1 if fail
fail=`egrep "Compiler Errors" oclint.log | wc -l`

if [ $fail -eq 1 ]; 
then
  echo "OCLint: Compiler error"
else
  echo "OCLint: OK"
fi

# Will be 1 if success
# Will be 0 if fail
success=`egrep "FilesWithViolations=0 P1=0 P2=0 P3=0" oclint.log | wc -l`

if [ $success -eq 1 ]; 
then
  echo "OCLint: OK"
else
  echo "OCLint: Fail"
  exit 1
fi