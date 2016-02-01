#include "create_direct_neighbour_named_vertices_subgraph.h"
#include "create_direct_neighbour_named_vertices_subgraph_demo.impl"

#include <cassert>
#include <iostream>

#include "create_named_vertices_k2_graph.h"
#include "create_named_vertices_k3_graph.h"
#include "get_vertex_names.h"

void create_direct_neighbour_named_vertices_subgraph_test() noexcept
{
  //K2
  {
    const auto g = create_named_vertices_k2_graph();
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i=vip.first; i!=j; ++i) {
      const auto h = create_direct_neighbour_named_vertices_subgraph(
        *i,g
      );
      assert(boost::num_vertices(h) == 2);
      assert(boost::num_edges(h) == 1);
      const auto v = get_vertex_names(h);
      std::set<std::string> names(std::begin(v),std::end(v));
      assert(names.count("Me") == 1);
      assert(names.count("My computer") == 1);
    }
  }
  //K3
  {
    const auto g = create_named_vertices_k3_graph();
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i=vip.first; i!=j; ++i) {
      const auto h = create_direct_neighbour_named_vertices_subgraph(
        *i,g
      );
      assert(boost::num_vertices(h) == 3);
      assert(boost::num_edges(h) == 3);
      const auto v = get_vertex_names(h);
      std::set<std::string> names(std::begin(v),std::end(v));
      assert(names.count("Karen") == 1);
      assert(names.count("Kristel") == 1);
      assert(names.count("Kathleen") == 1);
    }
  }

  create_direct_neighbour_named_vertices_subgraph_demo();
}
