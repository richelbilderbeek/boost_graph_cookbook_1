#ifndef HAS_EDGE_BETWEEN_VERTICES_H
#define HAS_EDGE_BETWEEN_VERTICES_H

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_traits.hpp>

//Please improve
template <typename graph>
bool has_edge_between_vertices(
  const typename boost::graph_traits<graph>::vertex_descriptor& vd_1,
  const typename boost::graph_traits<graph>::vertex_descriptor& vd_2,
  const graph& g
) noexcept
{
  if (degree(vd_1, g) //not boost::degree
    == 0) return false;
  if (degree(vd_2, g) //not boost::degree
    == 0) return false;
  for (auto eip = edges(g);
    eip.first != eip.second;
    ++eip.first) {
    const auto vd_3 = source(*eip.first, g);
    const auto vd_4 = target(*eip.first, g);
    if (vd_1 == vd_3 && vd_2 == vd_4) return true;
    if (vd_1 == vd_4 && vd_2 == vd_3) return true;
  }
  return false;
}

void has_edge_between_vertices_test() noexcept;

#endif // HAS_EDGE_BETWEEN_VERTICES_H
