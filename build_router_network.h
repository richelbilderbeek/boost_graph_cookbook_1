#ifndef BUILD_ROUTER_NETWORK_EXTERNAL_H
#define BUILD_ROUTER_NETWORK_EXTERNAL_H

#include <cassert>
#include <boost/graph/graph_traits.hpp>

//Build a router network supplying an external router name map and transmission delay map
//Modified from Siek, Jeremy G., Lie-Quan Lee, and Andrew Lumsdaine. Boost Graph Library: User Guide and Reference Manual, The. Pearson Education, 2001.
//Page 9
/*

 a --- 1.2 ---> b
 a --- 4.5 ---> d
 b --- 1.8 ---> d
 c --- 2.6 ---> a
 c --- 5.2 ---> e
 d --- 0.4 ---> c
 d --- 3.3 ---> e

*/
template <typename Graph, typename VertexNameMap, typename TransDelayMap>
void build_router_network(
  Graph& g,
  VertexNameMap& name_map,
  TransDelayMap& delay_map
)
{
  using my_vertex_descriptor = typename boost::graph_traits<Graph>::vertex_descriptor;
  //9a
  const my_vertex_descriptor va = add_vertex(g); name_map[va] = "a";
  const my_vertex_descriptor vb = add_vertex(g); name_map[vb] = "b";
  const my_vertex_descriptor vc = add_vertex(g); name_map[vc] = "c";
  const my_vertex_descriptor vd = add_vertex(g); name_map[vd] = "d";
  const my_vertex_descriptor ve = add_vertex(g); name_map[ve] = "e";

  //9b
  using my_edge_descriptor = typename boost::graph_traits<Graph>::edge_descriptor;

  //The boolean: if it has been successfully inserted
  using my_pair = std::pair<my_edge_descriptor,bool>;

  const my_pair ea = add_edge(va, vb, g); delay_map[ea.first] = 1.2; assert(ea.second);
  const my_pair eb = add_edge(va, vd, g); delay_map[eb.first] = 4.5; assert(eb.second);
  const my_pair ec = add_edge(vb, vd, g); delay_map[ec.first] = 1.8; assert(ec.second);
  const my_pair ed = add_edge(vc, va, g); delay_map[ed.first] = 2.6; assert(ed.second);
  const my_pair ee = add_edge(vc, ve, g); delay_map[ee.first] = 5.2; assert(ee.second);
  const my_pair ef = add_edge(vd, vc, g); delay_map[ef.first] = 0.4; assert(ef.second);
  const my_pair eg = add_edge(vd, ve, g); delay_map[eg.first] = 3.3; assert(eg.second);
}

void build_router_network_test() noexcept;

#endif // BUILD_ROUTER_NETWORK_EXTERNAL_H
