#include "my_custom_vertex.h"
//#include "my_custom_vertex_demo.impl"

#include <boost/test/unit_test.hpp>

#include <sstream>
#include <boost/lexical_cast.hpp>
#include "helper.h"
#include "seperate_string.h"
#include "graphviz_decode.h"
#include "graphviz_encode.h"

my_custom_vertex::my_custom_vertex(
  const std::string& name,
  const std::string& description,
  const double x,
  const double y
) noexcept :
  m_name{name},
  m_description{description},
  m_x{x},
  m_y{y}
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

const std::string& my_custom_vertex::get_description() const noexcept
{
  return m_description;
}

const std::string& my_custom_vertex::get_name() const noexcept
{
  return m_name;
}

double my_custom_vertex::get_x() const noexcept
{
  return m_x;
}

double my_custom_vertex::get_y() const noexcept
{
  return m_x;
}

BOOST_AUTO_TEST_CASE(my_custom_vertex_thorough)
{
  //Conversion to string
  {
    const my_custom_vertex in("A B","c d",1.0,2.0);
    std::stringstream s;
    s << in;
    const std::string t{s.str()};
    BOOST_CHECK(t.find(' ') == std::string::npos);
    BOOST_CHECK(std::count(std::begin(t),std::end(t),',') == 3);
  }
  //Conversion to stream and back
  {
    const my_custom_vertex in("A B","c d",1.0,2.0);
    std::stringstream s;
    s << in;
    my_custom_vertex out;
    s >> out;
    BOOST_CHECK(in == out);
  }
  //Conversion of two my_custom_vertex-es to stream and back
  {
    const my_custom_vertex a("A B","c d",1.0,2.0);
    const my_custom_vertex b("C","d",3.0,4.0);
    std::stringstream s;
    s << a << " " << b;
    my_custom_vertex c;
    my_custom_vertex d;
    s >> c >> d;
    BOOST_CHECK(a == c);
    BOOST_CHECK(b == d);
  }
  
}

bool operator==(const my_custom_vertex& lhs, const my_custom_vertex& rhs) noexcept
{
  return
       lhs.get_description() == rhs.get_description()
    && lhs.get_name() == rhs.get_name()
    && lhs.get_x() == rhs.get_x()
    && lhs.get_y() == rhs.get_y()
  ;
}

bool operator!=(const my_custom_vertex& lhs, const my_custom_vertex& rhs) noexcept
{
  return !(lhs == rhs);
}

bool operator<(const my_custom_vertex& lhs, const my_custom_vertex& rhs) noexcept
{
  if (lhs.get_name() < rhs.get_name()) return true;
  if (lhs.get_name() > rhs.get_name()) return false;
  if (lhs.get_description() < rhs.get_description()) return true;
  if (lhs.get_description() > rhs.get_description()) return false;
  if (lhs.get_x() < rhs.get_x()) return true;
  if (lhs.get_x() > rhs.get_x()) return false;
  return lhs.get_y() < rhs.get_y();
}

std::ostream& operator<<(std::ostream& os, const my_custom_vertex& v) noexcept
{
  os
    << graphviz_encode(v.get_name())
    << ","
    << graphviz_encode(v.get_description())
    << ","
    << v.get_x()
    << ","
    << v.get_y()
  ;
  return os;
}

std::istream& operator>>(std::istream& is, my_custom_vertex& v) noexcept
{
  std::string line;
  is >> line;
  BOOST_CHECK(line != "0");
  const auto w = seperate_string(line,',');
  BOOST_CHECK(w.size() == 4);
  my_custom_vertex new_vertex(
    graphviz_decode(w[0]),
    graphviz_decode(w[1]),
    boost::lexical_cast<double>(w[2]),
    boost::lexical_cast<double>(w[3])
  );
  v = new_vertex;
  return is;
}
