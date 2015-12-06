#include "my_vertex.h"

my_vertex::my_vertex(
  const std::string& name,
  const std::string& description,
  const double x,
  const double y
) :
  m_name{name},
  m_description{description},
  m_x{x},
  m_y{y}
{

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
