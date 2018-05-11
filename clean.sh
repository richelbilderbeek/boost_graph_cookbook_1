#!/bin/bash
function clean {
  rm *.o
  rm *.gcov
  rm *.gcda
  rm *.gcno
  rm Makefile
  rm Makefile.Debug
  rm Makefile.Release
  rm *.pro.user
  rm boost_graph_cookbook_1_test
  rm boost_graph_cookbook_1
  rm exe_debug.txt
  rm exe_release.txt
  rm test_debug.txt
  rm test_release.txt
  rm moc_*
  rm ui_*
  rm qrc_*
  rm -rf debug
  rm -rf release
  rm tmp*
}

rm -rf build-boost_graph_cookbook_1-Desktop-Debug
rm -rf build-boost_graph_cookbook_1-Desktop-Release
rm -rf build-boost_graph_cookbook_1_test-Desktop-Debug
rm -rf build-boost_graph_cookbook_1_test-Desktop-Release
rm create_*
clean


cd src; clean; cd ..
cd cpp; clean; cd ..
