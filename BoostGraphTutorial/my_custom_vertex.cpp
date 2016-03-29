#include "my_custom_vertex.h"

#include <sstream>
#include <stdexcept>
#include <boost/lexical_cast.hpp>
#include "helper.h"
#include "seperate_string.h"
#include "graphviz_decode.h"
#include "graphviz_encode.h"

my_custom_vertex::my_custom_vertex(
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

const std::string& my_custom_vertex::get_description() const noexcept
{
  return m_description;
}

const std::string& my_custom_vertex::get_name() const noexcept
{
  return m_name;
}

double my_custom_vertex::get_x() const noexcept
{
  return m_x;
}

double my_custom_vertex::get_y() const noexcept
{
  return m_x;
}

bool operator==(const my_custom_vertex& lhs, const my_custom_vertex& rhs) noexcept
{
  return
       lhs.get_description() == rhs.get_description()
    && lhs.get_name() == rhs.get_name()
    && lhs.get_x() == rhs.get_x()
    && lhs.get_y() == rhs.get_y()
  ;
}

bool operator!=(const my_custom_vertex& lhs, const my_custom_vertex& rhs) noexcept
{
  return !(lhs == rhs);
}

bool operator<(const my_custom_vertex& lhs, const my_custom_vertex& rhs) noexcept
{
  if (lhs.get_name() < rhs.get_name()) return true;
  if (lhs.get_name() > rhs.get_name()) return false;
  if (lhs.get_description() < rhs.get_description()) return true;
  if (lhs.get_description() > rhs.get_description()) return false;
  if (lhs.get_x() < rhs.get_x()) return true;
  if (lhs.get_x() > rhs.get_x()) return false;
  return lhs.get_y() < rhs.get_y();
}

std::ostream& operator<<(std::ostream& os, const my_custom_vertex& v) noexcept
{
  os
    << graphviz_encode(v.get_name())
    << ","
    << graphviz_encode(v.get_description())
    << ","
    << v.get_x()
    << ","
    << v.get_y()
  ;
  return os;
}

std::istream& operator>>(std::istream& is, my_custom_vertex& v)
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
  my_custom_vertex new_vertex(
    graphviz_decode(w[0]),
    graphviz_decode(w[1]),
    boost::lexical_cast<double>(w[2]),
    boost::lexical_cast<double>(w[3])
  );
  v = new_vertex;
  return is;
}
