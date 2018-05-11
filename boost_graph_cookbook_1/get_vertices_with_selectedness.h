#ifndef GET_VERTICES_WITH_SELECTEDNESS_H
#define GET_VERTICES_WITH_SELECTEDNESS_H

#include <vector>
#include "install_vertex_is_selected.h"

template <typename graph>
std::vector<
  typename boost::graph_traits<graph>::vertex_descriptor
>
get_vertices_with_selectedness(
  const bool selectedness,
  const graph& g
) noexcept
{
  using vd = typename boost::graph_traits<graph>::vertex_descriptor;
  std::vector<vd> vds;
  const auto vip = vertices(g);
  std::copy_if(vip.first,vip.second,std::back_inserter(vds),
    [selectedness, g](const vd d)
    {
      const auto is_selected_map = get(boost::vertex_is_selected, g);
      return get(is_selected_map, d) == selectedness;
    }
  );
  return vds;
}

#endif // GET_VERTICES_WITH_SELECTEDNESS_H
