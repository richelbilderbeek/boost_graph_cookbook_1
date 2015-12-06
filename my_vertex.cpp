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

