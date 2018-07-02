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

const std::string& my_bundled_vertex::get_description() const noexcept
{
  return m_description;
}

const std::string& my_bundled_vertex::get_name() const noexcept
{
  return m_name;
}

double my_bundled_vertex::get_x() const noexcept
{
  return m_x;
}

double my_bundled_vertex::get_y() const noexcept
{
  return m_y;
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

bool operator<(const my_bundled_vertex& lhs, const my_bundled_vertex& rhs) noexcept
{
  if (lhs.get_name() < rhs.get_name()) return true;
  if (lhs.get_name() > rhs.get_name()) return false;
  if (lhs.get_description() < rhs.get_description()) return true;
  if (lhs.get_description() > rhs.get_description()) return false;
  if (lhs.get_x() < rhs.get_x()) return true;
  if (lhs.get_x() > rhs.get_x()) return false;
  return lhs.get_y() < rhs.get_y();
}
