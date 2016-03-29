#include "my_bundled_edge.h"

#include "graphviz_decode.h"
#include "graphviz_encode.h"
#include <sstream>



my_bundled_edge::my_bundled_edge(
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

std::ostream& operator<<(std::ostream& os, const my_bundled_edge& v) noexcept
{
  os
    << graphviz_encode(v.m_name)
    << ","
    << graphviz_encode(v.m_description)
    << ","
    << v.m_width
    << ","
    << v.m_height
  ;
  return os;
}

bool operator==(const my_bundled_edge& lhs, const my_bundled_edge& rhs) noexcept
{
  return
       lhs.m_description == rhs.m_description
    && lhs.m_name == rhs.m_name
    && lhs.m_width == rhs.m_width
    && lhs.m_height == rhs.m_height
  ;
}

bool operator!=(const my_bundled_edge& lhs, const my_bundled_edge& rhs) noexcept
{
  return !(lhs == rhs);
}
