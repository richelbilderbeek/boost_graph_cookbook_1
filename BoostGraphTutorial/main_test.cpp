#include <fstream>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE boost_graph_tutorial_test_module
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(inform_travis)
{
  #ifndef NDEBUG
  std::ofstream f("test_debug.txt");
  #else
  std::ofstream f("test_release.txt");
  #endif
  f << "OK\n";
}
