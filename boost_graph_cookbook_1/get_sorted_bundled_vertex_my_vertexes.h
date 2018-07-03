#ifndef GET_SORTED_BUNDLED_VERTEX_MY_VERTEXES_H
#define GET_SORTED_BUNDLED_VERTEX_MY_VERTEXES_H

#include "get_my_bundled_vertexes.h"

template <typename graph>
std::vector<my_bundled_vertex> get_sorted_bundled_vertex_my_vertexes(
  const graph& g) noexcept
{
  auto v = get_my_bundled_vertexes(g);
  const auto mbvc // my_bundled_vertex_comparer
    = [](const my_bundled_vertex& lhs, const my_bundled_vertex& rhs) {
        if (lhs.m_name < rhs.m_name)
          return true;
        if (lhs.m_name > rhs.m_name)
          return false;
        if (lhs.m_description < rhs.m_description)
          return true;
        if (lhs.m_description > rhs.m_description)
          return false;
        if (lhs.m_x < rhs.m_x)
          return true;
        if (lhs.m_x > rhs.m_x)
          return false;
        return lhs.m_y < rhs.m_y;
      };
  std::sort(std::begin(v), std::end(v), mbvc);
  return v;
}

#endif // GET_SORTED_BUNDLED_VERTEX_MY_VERTEXES_H
