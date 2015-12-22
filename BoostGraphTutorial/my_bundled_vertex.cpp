#include "my_bundled_vertex.h"

#include <cassert>
#include <sstream>
#include <boost/lexical_cast.hpp>
#include "helper.h"
#include "seperate_string.h"
#include "is_read_graphviz_correct.h"

my_bundled_vertex::my_bundled_vertex(
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

void my_bundled_vertex_test() noexcept
{
  {
    const my_bundled_vertex in("A B","c d",1.0,2.0);
    std::stringstream s;
    s << in;
    my_bundled_vertex out;
    s >> out;
    assert(in == out);
  }
  {
    const my_bundled_vertex a("A B","c d",1.0,2.0);
    const my_bundled_vertex b("C","d",3.0,4.0);
    std::stringstream s;
    s << a << " " << b;
    my_bundled_vertex c;
    my_bundled_vertex d;
    s >> c >> d;
    assert(a == c);
    assert(b == d);
  }
  std::cout << __func__ << ": OK" << '\n';
}

bool operator==(const my_bundled_vertex& lhs, const my_bundled_vertex& rhs) noexcept
{
  return
       lhs.m_description == rhs.m_description
    && lhs.m_name == rhs.m_name
    && lhs.m_x == rhs.m_x
    && lhs.m_y == rhs.m_y
  ;
}

bool operator!=(const my_bundled_vertex& lhs, const my_bundled_vertex& rhs) noexcept
{
  return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& os, const my_bundled_vertex& v) noexcept
{
  os << v.m_name << ","
    << v.m_description << ","
    << v.m_x << ","
    << v.m_y
  ;
  return os;
}

std::istream& operator>>(std::istream& is, my_bundled_vertex& v) noexcept
{
  std::string line;
  is >> line;
  const auto w = seperate_string(line,',');
  if (w.size() != 4) { v = my_bundled_vertex(); return is; }
  assert(w.size() == 4);
  my_bundled_vertex new_vertex(
    w[0],
    w[1],
    boost::lexical_cast<double>(w[2]),
    boost::lexical_cast<double>(w[3])
  );
  v = new_vertex;
  return is;
}
