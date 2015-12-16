#include "my_vertex.h"

#include <cassert>
#include <sstream>
#include <boost/lexical_cast.hpp>
#include "helper.h"
#include "seperate_string.h"

my_vertex::my_vertex(
  const std::string& name,
  const std::string& description,
  const double x,
  const double y
) noexcept :
  m_name{helper().underscorify(name)},
  m_description{helper().underscorify(description)},
  m_x{x},
  m_y{y}
{
  assert(m_name.find(' ') == std::string::npos);
  assert(m_description.find(' ') == std::string::npos);
}

void my_vertex_test() noexcept
{
  {
    const my_vertex in("A B","c d",1.0,2.0);
    std::stringstream s;
    s << in;
    my_vertex out;
    s >> out;
    assert(in == out);
  }
  {
    const my_vertex a("A B","c d",1.0,2.0);
    const my_vertex b("C","d",3.0,4.0);
    std::stringstream s;
    s << a << " " << b;
    my_vertex c;
    my_vertex d;
    s >> c >> d;
    assert(a == c);
    assert(b == d);
  }
  std::cout << __func__ << ": OK" << '\n';
}

bool operator==(const my_vertex& lhs, const my_vertex& rhs) noexcept
{
  return
       lhs.m_description == rhs.m_description
    && lhs.m_name == rhs.m_name
    && lhs.m_x == rhs.m_x
    && lhs.m_y == rhs.m_y
  ;
}

bool operator!=(const my_vertex& lhs, const my_vertex& rhs) noexcept
{
  return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& os, const my_vertex& v) noexcept
{
  os << v.m_name << "," << v.m_description << "," << v.m_x << "," << v.m_y;
  return os;
}

std::istream& operator>>(std::istream& is, my_vertex& v) noexcept
{
  std::string line;
  is >> line;
  const auto w = seperate_string(line,',');
  assert(w.size() == 4);
  v.m_name = w[0];
  v.m_description = w[1];
  v.m_x = boost::lexical_cast<double>(w[2]);
  v.m_y = boost::lexical_cast<double>(w[3]);
  return is;
}
