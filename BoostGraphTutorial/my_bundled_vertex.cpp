#include "my_bundled_vertex.h"

#include <sstream>
#include "graphviz_decode.h"
#include "graphviz_encode.h"

my_bundled_vertex::my_bundled_vertex(
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

}

std::ostream& operator<<(std::ostream& os, const my_bundled_vertex& v) noexcept
{
  os
    << graphviz_encode(v.m_name)
    << ","
    << graphviz_encode(v.m_description)
    << ","
    << v.m_x
    << ","
    << v.m_y
  ;
  return os;
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
