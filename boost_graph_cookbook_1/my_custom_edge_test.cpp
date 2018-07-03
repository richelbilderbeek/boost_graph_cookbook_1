#include "my_custom_edge.h"
//#include "my_custom_edge_demo.impl"

#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>
#include <sstream>

#include <boost/lexical_cast.hpp>

#include "file_to_vector.h"
#include "graphviz_decode.h"
#include "graphviz_encode.h"
#include "seperate_string.h"

BOOST_AUTO_TEST_CASE(test_my_custom_edge_copy_construction)
{
  const my_custom_edge a("A B", "c d", 1.0, 2.0);
  const my_custom_edge b{ a };
  BOOST_CHECK(a == b);
}

BOOST_AUTO_TEST_CASE(test_my_custom_edge_construction)
{
  const std::string name = "a nice name";
  const std::string description = "can be anything";
  const double width = 3.14;
  const double height = 2.71;
  my_custom_edge v(name, description, width, height);
  BOOST_CHECK_EQUAL(v.get_description(), description);
  BOOST_CHECK_EQUAL(v.get_name(), name);
  BOOST_CHECK_EQUAL(v.get_width(), width);
  BOOST_CHECK_EQUAL(v.get_height(), height);
}

BOOST_AUTO_TEST_CASE(test_my_custom_edge_compare_operators)
{
  const my_custom_edge a("A B", "c d", 1.0, 2.0);
  const my_custom_edge b("A B", "c d", 1.0, 2.0);
  const my_custom_edge c("A B", "x x", 1.0, 2.0);
  const my_custom_edge d("A B", "c d", 9.9, 2.0);
  const my_custom_edge e("A B", "c d", 1.0, 9.9);
  BOOST_CHECK_EQUAL(a, b);
  BOOST_CHECK_NE(a, c);
  BOOST_CHECK_NE(b, c);
  BOOST_CHECK_NE(c, d);
  BOOST_CHECK_NE(d, e);
  BOOST_CHECK_NE(e, a);
}

BOOST_AUTO_TEST_CASE(test_my_custom_edge_conversion_to_string)
{
  const my_custom_edge in("A B", "c d", 1.0, 2.0);
  std::stringstream s;
  s << in;
  const std::string t{ s.str() };
  BOOST_CHECK(t.find(' ') == std::string::npos);
  BOOST_CHECK(std::count(std::begin(t), std::end(t), ',') == 3);
}

BOOST_AUTO_TEST_CASE(test_my_custom_edge_conversion_to_stream_and_back)
{
  const my_custom_edge in("AB", "cd", 1.0, 2.0);
  std::stringstream s;
  s << in;
  my_custom_edge out;
  s >> out;
  BOOST_CHECK(in == out);
}

BOOST_AUTO_TEST_CASE(test_my_custom_edge_two_edges_to_stream_and_back)
{
  const my_custom_edge a("AB", "cd", 1.0, 2.0);
  const my_custom_edge b("C D", "d e", 3.0, 4.0);
  std::stringstream s;
  s << a << " " << b;
  my_custom_edge c;
  my_custom_edge d;
  s >> c >> d;
  BOOST_CHECK(a == c);
  BOOST_CHECK(b == d);
}

BOOST_AUTO_TEST_CASE(test_my_custom_edge_stream_from_invalid_input)
{
  std::stringstream s;
  s << "A,B,1.0,2.0,3.0";
  my_custom_edge e;
  BOOST_CHECK_THROW(s >> e, std::runtime_error);
}
