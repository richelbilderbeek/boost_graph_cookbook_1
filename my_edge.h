#ifndef MY_EDGE_H
#define MY_EDGE_H

#include <string>

class my_edge
{
public:
  my_edge(
    const std::string& name = "",
    const std::string& description = "",
    const double width = 1.0,
    const double height = 1.0
  ) noexcept;
  std::string m_name;
  std::string m_description;
  double m_width;
  double m_height;
};

bool operator==(const my_edge& lhs, const my_edge& rhs) noexcept;

#endif // MY_EDGE_H
