#ifndef GET_SORTED_BUNDLED_EDGE_MY_EDGES_H
#define GET_SORTED_BUNDLED_EDGE_MY_EDGES_H

#include "get_my_bundled_edges.h"

#include <vector>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/properties.hpp>
#include "my_bundled_edge.h"

template <typename graph>
std::vector<my_bundled_edge> get_sorted_bundled_edge_my_edges(const graph& g) noexcept
{
  auto v = get_my_bundled_edges(g);

  const auto my_bundled_edge_comparer
    = [](const my_bundled_edge& lhs,const my_bundled_edge& rhs)
        {
          if (lhs.m_name < rhs.m_name) return true;
          if (lhs.m_name > rhs.m_name) return false;
          if (lhs.m_description < rhs.m_description) return true;
          if (lhs.m_description > rhs.m_description) return false;
          if (lhs.m_width < rhs.m_width) return true;
          if (lhs.m_width > rhs.m_width) return false;
          return lhs.m_height < rhs.m_width;
        }
  ;
  std::sort(std::begin(v),std::end(v), my_bundled_edge_comparer);
  return v;
}


#endif // GET_SORTED_BUNDLED_EDGE_MY_EDGES_H
