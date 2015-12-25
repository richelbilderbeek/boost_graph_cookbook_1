#ifndef GET_SORTED_CUSTOM_EDGE_MY_EDGES_H
#define GET_SORTED_CUSTOM_EDGE_MY_EDGES_H

#include <vector>
#include "get_custom_edge_my_edges.h"

template <typename graph>
std::vector<my_custom_edge> get_sorted_custom_edge_my_edges(const graph& g) noexcept
{
  auto v = get_custom_edge_my_edges(g);

  const auto my_custom_edge_comparer
    = [](const my_custom_edge& lhs,const my_custom_edge& rhs)
        {
          if (lhs.get_name() < rhs.get_name()) return true;
          if (lhs.get_name() > rhs.get_name()) return false;
          if (lhs.get_description() < rhs.get_description()) return true;
          if (lhs.get_description() > rhs.get_description()) return false;
          if (lhs.get_width() < rhs.get_width()) return true;
          if (lhs.get_width() > rhs.get_width()) return false;
          return lhs.get_height() < rhs.get_width();
        }
  ;
  std::sort(std::begin(v),std::end(v), my_custom_edge_comparer);
  return v;
}


#endif // GET_SORTED_CUSTOM_EDGE_MY_EDGES_H
