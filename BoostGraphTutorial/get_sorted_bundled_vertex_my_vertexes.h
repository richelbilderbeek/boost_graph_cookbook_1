#ifndef GET_SORTED_BUNDLED_VERTEX_MY_VERTEXES_H
#define GET_SORTED_BUNDLED_VERTEX_MY_VERTEXES_H

#include "get_bundled_vertex_my_vertexes.h"

#include <vector>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/properties.hpp>
#include "my_bundled_vertex.h"

///Collect all the my_bundled_vertex objects from a graph
///stored as a custom property of a vertex and
///sort these before returning
//TODO: generalize to return any type
template <typename graph>
std::vector<my_bundled_vertex> get_sorted_bundled_vertex_my_vertexes(const graph& g) noexcept
{
  auto v = get_bundled_vertex_my_vertexes(g);

  const auto my_bundled_vertex_comparer
    = [](const my_bundled_vertex& lhs,const my_bundled_vertex& rhs)
        {
          if (lhs.m_name < rhs.m_name) return true;
          if (lhs.m_name > rhs.m_name) return false;
          if (lhs.m_description < rhs.m_description) return true;
          if (lhs.m_description > rhs.m_description) return false;
          if (lhs.m_x < rhs.m_x) return true;
          if (lhs.m_x > rhs.m_x) return false;
          return lhs.m_y < rhs.m_y;
        }
  ;
  std::sort(std::begin(v),std::end(v), my_bundled_vertex_comparer);
  return v;
}


#endif // GET_SORTED_BUNDLED_VERTEX_MY_VERTEXES_H
