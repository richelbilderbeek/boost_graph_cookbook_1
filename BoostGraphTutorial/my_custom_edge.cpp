#include "my_custom_edge.h"
#include <cassert>
#include <sstream>

#include <boost/lexical_cast.hpp>

#include "file_to_vector.h"
#include "seperate_string.h"
#include "graphviz_decode.h"
#include "graphviz_encode.h"

my_custom_edge::my_custom_edge(
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
  if(graphviz_decode(graphviz_encode(m_name)) != m_name)
  {
    std::stringstream msg;
    msg << __func__ << ": cannot successfully encode and decode the name '"
      << m_name << "', it will be turned into '"
      << graphviz_decode(graphviz_encode(m_name))
      << "'"
    ;
    throw std::logic_error(msg.str());
  }
  if(graphviz_decode(graphviz_encode(m_description)) != m_description)
  {
    std::stringstream msg;
    msg << __func__ << ": cannot successfully encode and decode the description '"
      << m_description << "', it will be turned into '"
      << graphviz_decode(graphviz_encode(m_description))
      << "'"
    ;
    throw std::logic_error(msg.str());
  }
}

const std::string& my_custom_edge::get_description() const noexcept
{
  return m_description;
}

const std::string& my_custom_edge::get_name() const noexcept
{
  return m_name;
}

double my_custom_edge::get_width() const noexcept
{
  return m_width;
}

double my_custom_edge::get_height() const noexcept
{
  return m_height;
}

bool operator==(const my_custom_edge& lhs, const my_custom_edge& rhs) noexcept
{
  return
       lhs.get_description() == rhs.get_description()
    && lhs.get_name() == rhs.get_name()
    && lhs.get_width() == rhs.get_width()
    && lhs.get_height() == rhs.get_height()
  ;
}

bool operator!=(const my_custom_edge& lhs, const my_custom_edge& rhs) noexcept
{
  return !(lhs == rhs);
}

bool operator<(const my_custom_edge& lhs, const my_custom_edge& rhs) noexcept
{
  if (lhs.get_name() < rhs.get_name()) return true;
  if (lhs.get_name() > rhs.get_name()) return false;
  if (lhs.get_description() < rhs.get_description()) return true;
  if (lhs.get_description() > rhs.get_description()) return false;
  if (lhs.get_width() < rhs.get_width()) return true;
  if (lhs.get_width() > rhs.get_width()) return false;
  return lhs.get_height() < rhs.get_height();
}

std::ostream& operator<<(std::ostream& os, const my_custom_edge& v) noexcept
{
  os
    << graphviz_encode(v.get_name())
    << ","
    << graphviz_encode(v.get_description())
    << ","
    << v.get_width()
    << ","
    << v.get_height()
  ;
  return os;
}

std::istream& operator>>(std::istream& is, my_custom_edge& the_edge)
{
  std::string line;
  is >> line;
  const auto w = seperate_string(line,',');
  if (w.size() != 4)
  {
    std::stringstream msg;
    msg << __func__ << ": "
      << "invalid line with " << w.size()
      << " instead of four elements"
    ;
    throw std::runtime_error(msg.str());
  }
  the_edge = my_custom_edge(
    graphviz_decode(w[0]),
    graphviz_decode(w[1]),
    boost::lexical_cast<double>(w[2]),
    boost::lexical_cast<double>(w[3])
  );
  return is;
}
