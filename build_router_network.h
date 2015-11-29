#ifndef BUILD_ROUTER_NETWORK_H
#define BUILD_ROUTER_NETWORK_H

#include <boost/graph/graph_traits.hpp>

//From Siek, Jeremy G., Lie-Quan Lee, and Andrew Lumsdaine. Boost Graph Library: User Guide and Reference Manual, The. Pearson Education, 2001.
//Page 9
template <typename Graph, typename VertexNameMap, typename TransDelayMap>
void build_router_network(Graph& g, VertexNameMap name_map,
  TransDelayMap delay_map)
{
  //9a
  typename boost::graph_traits<Graph>::vertex_descriptor a, b, c, d, e;
  a = add_vertex(g); name_map[a] = 'a';
  b = add_vertex(g); name_map[a] = 'b';
  c = add_vertex(g); name_map[a] = 'c';
  d = add_vertex(g); name_map[a] = 'd';
  e = add_vertex(g); name_map[a] = 'e';

  //9b
  typename boost::graph_traits<Graph>::edge_descriptor ed;
  bool inserted;

  tie(ed, inserted) = add_edge(a, b, g);
  delay_map[ed] = 1.2;
  tie(ed, inserted) = add_edge(a, d, g);
  delay_map[ed] = 4.5;
  tie(ed, inserted) = add_edge(b, d, g);
  delay_map[ed] = 1.8;
  tie(ed, inserted) = add_edge(c, a, g);
  delay_map[ed] = 2.6;
  tie(ed, inserted) = add_edge(c, e, g);
  delay_map[ed] = 5.2;
  tie(ed, inserted) = add_edge(d, c, g);
  delay_map[ed] = 0.4;
  tie(ed, inserted) = add_edge(d, e, g);
  delay_map[ed] = 3.3;
}

void test_build_router_network() noexcept;

#endif // BUILD_ROUTER_NETWORK_H
