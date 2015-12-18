#include "my_edge.h"

#include <cassert>
#include <sstream>
#include <iostream>

#include <boost/lexical_cast.hpp>

#include "seperate_string.h"

my_edge::my_edge(
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

}

void my_edge_test() noexcept
{
  {
    const my_edge in("AB","cd",1.0,2.0);
    std::stringstream s;
    s << in;
    my_edge out;
    s >> out;
    assert(in == out);
  }
  {
    const my_edge a("AB","cd",1.0,2.0);
    const my_edge b("C","d",3.0,4.0);
    std::stringstream s;
    s << a << " " << b;
    my_edge c;
    my_edge d;
    s >> c >> d;
    assert(a == c);
    assert(b == d);
  }
  std::cout << __func__ << ": OK" << '\n';
}

bool operator==(const my_edge& lhs, const my_edge& rhs) noexcept
{
  return
       lhs.m_description == rhs.m_description
    && lhs.m_name == rhs.m_name
    && lhs.m_width == rhs.m_width
    && lhs.m_height == rhs.m_height
  ;
}

bool operator!=(const my_edge& lhs, const my_edge& rhs) noexcept
{
  return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& os, const my_edge& v) noexcept
{
  os << v.m_name << "," << v.m_description << "," << v.m_width << "," << v.m_height;
  return os;
}

std::istream& operator>>(std::istream& is, my_edge& v) noexcept
{
  std::string line;
  is >> line;
  const auto w = seperate_string(line,',');
  if (w.size() != 4) { v = my_edge(); return is; }
  assert(w.size() == 4);
  v.m_name = w[0];
  v.m_description = w[1];
  v.m_width = boost::lexical_cast<double>(w[2]);
  v.m_height = boost::lexical_cast<double>(w[3]);
  return is;
}
