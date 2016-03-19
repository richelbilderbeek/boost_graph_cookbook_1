#include "my_custom_edge.h"
//#include "my_custom_edge_demo.impl"

#include <boost/test/unit_test.hpp>

#include <sstream>
#include <boost/test/unit_test.hpp>

#include <boost/lexical_cast.hpp>

#include "helper.h"
#include "seperate_string.h"
#include "graphviz_decode.h"
#include "graphviz_encode.h"

my_custom_edge::my_custom_edge(
  const std::string& name,
  const std::string& description,
  const double width,
  const double height
) noexcept
  : m_name{name},
    m_description{description},
    m_width{width},
    m_height{height}
{
  BOOST_CHECK(
    graphviz_decode(
      graphviz_encode(m_name)
    ) == m_name
  );
  BOOST_CHECK(
    graphviz_decode(
      graphviz_encode(m_description)
    ) == m_description
  );
}

const std::string& my_custom_edge::get_description() const noexcept
{
  return m_description;
}

const std::string& my_custom_edge::get_name() const noexcept
{
  return m_name;
}

double my_custom_edge::get_width() const noexcept
{
  return m_width;
}

double my_custom_edge::get_height() const noexcept
{
  return m_height;
}


BOOST_AUTO_TEST_CASE(my_custom_edge_thorough)
{
  {
    const my_custom_edge a("A B","c d",1.0,2.0);
    const my_custom_edge b{a};
    BOOST_CHECK(a == b);
  }
  //Conversion to string
  {
    const my_custom_edge in("A B","c d",1.0,2.0);
    std::stringstream s;
    s << in;
    const std::string t{s.str()};
    BOOST_CHECK(t.find(' ') == std::string::npos);
    BOOST_CHECK(std::count(std::begin(t),std::end(t),',') == 3);
  }
  //Conversion to stream and back
  {
    const my_custom_edge in("AB","cd",1.0,2.0);
    std::stringstream s;
    s << in;
    my_custom_edge out;
    s >> out;
    BOOST_CHECK(in == out);
  }
  //Conversion of two my_custom_edges to stream and back
  {
    const my_custom_edge a("AB","cd",1.0,2.0);
    const my_custom_edge b("C D","d e",3.0,4.0);
    std::stringstream s;
    s << a << " " << b;
    my_custom_edge c;
    my_custom_edge d;
    s >> c >> d;
    BOOST_CHECK(a == c);
    BOOST_CHECK(b == d);
  }
  
}

bool operator==(const my_custom_edge& lhs, const my_custom_edge& rhs) noexcept
{
  return
       lhs.get_description() == rhs.get_description()
    && lhs.get_name() == rhs.get_name()
    && lhs.get_width() == rhs.get_width()
    && lhs.get_height() == rhs.get_height()
  ;
}

bool operator!=(const my_custom_edge& lhs, const my_custom_edge& rhs) noexcept
{
  return !(lhs == rhs);
}

bool operator<(const my_custom_edge& lhs, const my_custom_edge& rhs) noexcept
{
  if (lhs.get_name() < rhs.get_name()) return true;
  if (lhs.get_name() > rhs.get_name()) return false;
  if (lhs.get_description() < rhs.get_description()) return true;
  if (lhs.get_description() > rhs.get_description()) return false;
  if (lhs.get_width() < rhs.get_width()) return true;
  if (lhs.get_width() > rhs.get_width()) return false;
  return lhs.get_height() < rhs.get_height();
}

std::ostream& operator<<(std::ostream& os, const my_custom_edge& v) noexcept
{
  os
    << graphviz_encode(v.get_name())
    << ","
    << graphviz_encode(v.get_description())
    << ","
    << v.get_width()
    << ","
    << v.get_height()
  ;
  return os;
}

std::istream& operator>>(std::istream& is, my_custom_edge& the_edge) noexcept
{
  std::string line;
  is >> line;
  BOOST_CHECK(line != "0");
  const auto w = seperate_string(line,',');
  if (w.size() != 4) { the_edge = my_custom_edge(); return is; }
  BOOST_CHECK(w.size() == 4);
  the_edge = my_custom_edge(
    graphviz_decode(w[0]),
    graphviz_decode(w[1]),
    boost::lexical_cast<double>(w[2]),
    boost::lexical_cast<double>(w[3])
  );
  return is;
}
