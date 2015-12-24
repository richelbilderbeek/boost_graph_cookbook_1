#include "my_custom_vertex.h"

#include <iostream>
#include <cassert>
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
  assert(
    graphviz_decode(
      graphviz_encode(m_name)
    ) == m_name
  );
  assert(
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

void my_custom_vertex_test() noexcept
{
  //Conversion to string
  {
    const my_custom_vertex in("A B","c d",1.0,2.0);
    std::stringstream s;
    s << in;
    const std::string t{s.str()};
    assert(t.find(' ') == std::string::npos);
    assert(std::count(std::begin(t),std::end(t),',') == 3);
  }
  //Conversion to stream and back
  {
    const my_custom_vertex in("A B","c d",1.0,2.0);
    std::stringstream s;
    s << in;
    my_custom_vertex out;
    s >> out;
    assert(in == out);
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
    assert(a == c);
    assert(b == d);
  }
  std::cout << __func__ << ": OK" << '\n';
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
  const auto w = seperate_string(line,',');
  if (w.size() != 4) { v = my_custom_vertex(); return is; }
  assert(w.size() == 4);
  my_custom_vertex new_vertex(
    graphviz_decode(w[0]),
    graphviz_decode(w[1]),
    boost::lexical_cast<double>(w[2]),
    boost::lexical_cast<double>(w[3])
  );
  v = new_vertex;
  return is;
}
