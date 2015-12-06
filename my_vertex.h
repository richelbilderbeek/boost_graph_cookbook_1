#ifndef MY_VERTEX_H
#define MY_VERTEX_H

#include <string>

class my_vertex
{
public:
  my_vertex(
    const std::string& name = "",
    const std::string& description = "",
    const double x = 0.0,
    const double y = 0.0
  );
  std::string m_name;
  std::string m_description;
  double m_x;
  double m_y;
};

#endif // MY_VERTEX_H
