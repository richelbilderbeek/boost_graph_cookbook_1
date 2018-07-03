#include "my_custom_vertex.h"
//#include "my_custom_vertex_demo.impl"

#include <boost/test/unit_test.hpp>

#include "file_to_vector.h"
#include "graphviz_decode.h"
#include "graphviz_encode.h"
#include "seperate_string.h"
#include <boost/lexical_cast.hpp>
#include <sstream>

BOOST_AUTO_TEST_CASE(test_my_custom_vertex_construction)
{
  const std::string name = "a nice name";
  const std::string description = "can be anything";
  const double x = 3.14;
  const double y = 2.71;
  my_custom_vertex v(name, description, x, y);
  BOOST_CHECK_EQUAL(v.get_description(), description);
  BOOST_CHECK_EQUAL(v.get_name(), name);
  BOOST_CHECK_EQUAL(v.get_x(), x);
  BOOST_CHECK_EQUAL(v.get_y(), y);
}

BOOST_AUTO_TEST_CASE(test_my_custom_vertex_equality_operators)
{
  const my_custom_vertex a("A B", "c d", 1.0, 2.0);
  const my_custom_vertex b("A B", "c d", 1.0, 2.0);
  const my_custom_vertex c("A B", "x x", 1.0, 2.0);
  const my_custom_vertex d("A B", "c d", 9.0, 2.0);
  const my_custom_vertex e("A B", "c d", 1.0, 9.0);
  BOOST_CHECK_EQUAL(a, b);
  BOOST_CHECK_NE(b, c);
  BOOST_CHECK_NE(c, d);
  BOOST_CHECK_NE(d, e);
  BOOST_CHECK_NE(e, a);
}

BOOST_AUTO_TEST_CASE(test_my_custom_vertex_to_string)
{
  const my_custom_vertex in("A B", "c d", 1.0, 2.0);
  std::stringstream s;
  s << in;
  const std::string t{ s.str() };
  BOOST_CHECK(t.find(' ') == std::string::npos);
  BOOST_CHECK(std::count(std::begin(t), std::end(t), ',') == 3);
}

BOOST_AUTO_TEST_CASE(test_my_custom_vertex_to_stream_and_back)
{
  const my_custom_vertex in("A B", "c d", 1.0, 2.0);
  std::stringstream s;
  s << in;
  my_custom_vertex out;
  s >> out;
  BOOST_CHECK(in == out);
}

BOOST_AUTO_TEST_CASE(test_my_custom_vertex_two_to_stream_and_back)
{
  const my_custom_vertex a("A B", "c d", 1.0, 2.0);
  const my_custom_vertex b("C", "d", 3.0, 4.0);
  std::stringstream s;
  s << a << " " << b;
  my_custom_vertex c;
  my_custom_vertex d;
  s >> c >> d;
  BOOST_CHECK(a == c);
  BOOST_CHECK(b == d);
}

BOOST_AUTO_TEST_CASE(test_my_custom_vertex_ordering)
{
  const my_custom_vertex a("A");
  const my_custom_vertex b("B");
  BOOST_CHECK(a < b);
}
