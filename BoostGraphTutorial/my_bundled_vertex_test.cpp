#include "my_bundled_vertex.h"

#include <sstream>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_my_bundled_vertex_default_construction)
{
  const my_bundled_vertex a;
  BOOST_CHECK_EQUAL(a.m_description, "");
  BOOST_CHECK_EQUAL(a.m_y, 0.0);
  BOOST_CHECK_EQUAL(a.m_name, "");
  BOOST_CHECK_EQUAL(a.m_x, 0.0);
}

BOOST_AUTO_TEST_CASE(test_my_bundled_vertex_copy_construction)
{
  const std::string description{"description"};
  const std::string name{"name"};
  const double y{12.34};
  const double x{123.456};
  const my_bundled_vertex a(
    name,
    description,
    x,
    y
  );
  const my_bundled_vertex b(a);
  BOOST_CHECK_EQUAL(b.m_description, description);
  BOOST_CHECK_EQUAL(b.m_y, y);
  BOOST_CHECK_EQUAL(b.m_name, name);
  BOOST_CHECK_EQUAL(b.m_x, x);
}

BOOST_AUTO_TEST_CASE(test_my_bundled_vertex_comparison)
{
  const std::string description{"description"};
  const std::string name{"name"};
  const double y{12.34};
  const double x{123.456};
  const my_bundled_vertex a(
    name,
    description,
    x,
    y
  );
  const my_bundled_vertex b(a);
  const my_bundled_vertex c;
  BOOST_CHECK(a == b);
  BOOST_CHECK(b == a);
  BOOST_CHECK(a != c);
  BOOST_CHECK(b != c);
  BOOST_CHECK(c != a);
  BOOST_CHECK(c != b);
}

BOOST_AUTO_TEST_CASE(test_my_bundled_vertex_stream_operator)
{
  const my_bundled_vertex a("name");
  std::stringstream s;
  s << a;
  BOOST_CHECK(!s.str().empty());
}
