#include "my_edge.h"

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

bool operator==(const my_edge& lhs, const my_edge& rhs) noexcept
{
  return
       lhs.m_name == rhs.m_name
    && lhs.m_description == rhs.m_description
    && lhs.m_width == rhs.m_width
    && lhs.m_height == rhs.m_height
  ;
}
