#!/bin/bash
function clean {
  rm *.o
  rm *.gcov
  rm Makefile
  rm Makefile.Debug
  rm Makefile.Release
  rm *.pro.user
  rm distancer_exe
  rm distancer_test
  rm exe_debug.txt
  rm exe_release.txt
  rm test_debug.txt
  rm test_release.txt
  rm -rf debug
  rm -rf release
}

clean
cd src; clean; cd ..
cd cpp; clean; cd ..
rm -rf build-distancer_exe-Desktop-Debug
rm -rf build-distancer_exe-Desktop-Release
rm -rf build-distancer_test-Desktop-Debug
rm -rf build-distancer_test-Desktop-Release