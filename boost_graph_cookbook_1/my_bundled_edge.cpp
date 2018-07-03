#include "my_bundled_edge.h"

#include "graphviz_decode.h"
#include "graphviz_encode.h"
#include <sstream>

my_bundled_edge::my_bundled_edge(const std::string& name,
  const std::string& description, const double width,
  const double height) noexcept
  : m_name{ name }
  , m_description{ description }
  , m_width{ width }
  , m_height{ height }
{
}

const std::string& my_bundled_edge::get_description() const noexcept
{
  return m_description;
}

double my_bundled_edge::get_height() const noexcept { return m_height; }

const std::string& my_bundled_edge::get_name() const noexcept { return m_name; }

double my_bundled_edge::get_width() const noexcept { return m_width; }

std::ostream& operator<<(std::ostream& os, const my_bundled_edge& v) noexcept
{
  os << graphviz_encode(v.m_name) << "," << graphviz_encode(v.m_description)
     << "," << v.m_width << "," << v.m_height;
  return os;
}

bool operator==(const my_bundled_edge& lhs, const my_bundled_edge& rhs) noexcept
{
  return lhs.m_description == rhs.m_description && lhs.m_name == rhs.m_name
    && lhs.m_width == rhs.m_width && lhs.m_height == rhs.m_height;
}

bool operator!=(const my_bundled_edge& lhs, const my_bundled_edge& rhs) noexcept
{
  return !(lhs == rhs);
}

bool operator<(const my_bundled_edge& lhs, const my_bundled_edge& rhs) noexcept
{
  if (lhs.get_name() < rhs.get_name())
    return true;
  if (lhs.get_name() > rhs.get_name())
    return false;
  if (lhs.get_description() < rhs.get_description())
    return true;
  if (lhs.get_description() > rhs.get_description())
    return false;
  if (lhs.get_width() < rhs.get_width())
    return true;
  if (lhs.get_width() > rhs.get_width())
    return false;
  return lhs.get_height() < rhs.get_height();
}
