#include "my_bundled_edge.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_my_bundled_edge_default_construction)
{
  const my_bundled_edge a;
  BOOST_CHECK_EQUAL(a.m_description, "");
  BOOST_CHECK_EQUAL(a.m_height, 1.0);
  BOOST_CHECK_EQUAL(a.m_name, "");
  BOOST_CHECK_EQUAL(a.m_width, 1.0);
}

BOOST_AUTO_TEST_CASE(test_my_bundled_edge_copy_construction)
{
  const std::string description{ "description" };
  const std::string name{ "name" };
  const double height{ 12.34 };
  const double width{ 123.456 };
  const my_bundled_edge a(name, description, width, height);
  const my_bundled_edge b(a);
  BOOST_CHECK_EQUAL(b.m_description, description);
  BOOST_CHECK_EQUAL(b.m_height, height);
  BOOST_CHECK_EQUAL(b.m_name, name);
  BOOST_CHECK_EQUAL(b.m_width, width);
}

BOOST_AUTO_TEST_CASE(test_my_bundled_edge_comparison)
{
  const std::string description{ "description" };
  const std::string name{ "name" };
  const double height{ 12.34 };
  const double width{ 123.456 };
  const my_bundled_edge a(name, description, width, height);
  const my_bundled_edge b(a);
  const my_bundled_edge c;
  BOOST_CHECK(a == b);
  BOOST_CHECK(b == a);
  BOOST_CHECK(a != c);
  BOOST_CHECK(b != c);
  BOOST_CHECK(c != a);
  BOOST_CHECK(c != b);
}

BOOST_AUTO_TEST_CASE(test_my_bundled_edge_stream_operator)
{
  const my_bundled_edge a("name");
  std::stringstream s;
  s << a;
  BOOST_CHECK(!s.str().empty());
}
