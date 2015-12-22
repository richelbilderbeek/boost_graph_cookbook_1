#ifndef MY_CUSTOM_EDGE_H
#define MY_CUSTOM_EDGE_H

#include <string>

class my_custom_edge
{
public:
  my_custom_edge(
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

bool operator==(const my_custom_edge& lhs, const my_custom_edge& rhs) noexcept;
bool operator!=(const my_custom_edge& lhs, const my_custom_edge& rhs) noexcept;
std::ostream& operator<<(std::ostream& os, const my_custom_edge& v) noexcept;
std::istream& operator>>(std::istream& os, my_custom_edge& v) noexcept;

void my_custom_edge_test() noexcept;

#endif // MY_CUSTOM_EDGE_H
