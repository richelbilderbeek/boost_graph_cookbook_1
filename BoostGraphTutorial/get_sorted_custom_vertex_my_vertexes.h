#ifndef GET_SORTED_CUSTOM_VERTEX_MY_VERTEXES_H
#define GET_SORTED_CUSTOM_VERTEX_MY_VERTEXES_H

#include "get_my_custom_vertexes.h"

#include <vector>

template <typename graph>
std::vector<my_custom_vertex> get_sorted_custom_vertex_my_vertexes(const graph& g) noexcept
{
  auto v = get_my_custom_vertexes(g);
  std::sort(std::begin(v),std::end(v));
  /*
  const auto mcvc //my_custom_vertex_comparer
    = [](const my_custom_vertex& lhs,const my_custom_vertex& rhs)
        {
          if (lhs.get_name() < rhs.get_name()) return true;
          if (lhs.get_name() > rhs.get_name()) return false;
          if (lhs.get_description() < rhs.get_description()) return true;
          if (lhs.get_description() > rhs.get_description()) return false;
          if (lhs.get_x() < rhs.get_x()) return true;
          if (lhs.get_x() > rhs.get_x()) return false;
          return lhs.get_y() < rhs.get_y();
        }
  ;
  std::sort(std::begin(v),std::end(v), mcvc);
  */
  return v;
}

#endif // GET_SORTED_CUSTOM_VERTEX_MY_VERTEXES_H
