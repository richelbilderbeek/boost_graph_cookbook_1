#include "create_all_direct_neighbour_named_edges_and_vertices_subgraphs.h"

#include "create_all_direct_neighbour_named_edges_and_vertices_subgraphs_demo.impl"

#include <cassert>
#include <iostream>
#include "create_named_edges_and_vertices_k2_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"
#include "create_named_edges_and_vertices_petersen_graph.h"

void create_all_direct_neighbour_named_edges_and_vertices_subgraphs_test() noexcept
{
  //K2
  {
    const auto v = create_all_direct_neighbour_named_edges_and_vertices_subgraphs(create_named_edges_and_vertices_k2_graph());
    assert(v.size() == 2);
    for (const auto g: v)
    {
      assert(boost::num_vertices(g) == 2);
      assert(boost::num_edges(g) == 1);
    }
  }
  //K3
  {
    const auto v = create_all_direct_neighbour_named_edges_and_vertices_subgraphs(create_named_edges_and_vertices_k3_graph());
    assert(v.size() == 3);
    for (const auto g: v)
    {
      assert(boost::num_vertices(g) == 3);
      assert(boost::num_edges(g) == 3);
    }
  }
  //Petersen Graph
  {
    const auto v = create_all_direct_neighbour_named_edges_and_vertices_subgraphs(create_named_edges_and_vertices_petersen_graph());
    assert(v.size() == 10);
    for (const auto g: v)
    {
      assert(boost::num_vertices(g) == 4);
      assert(boost::num_edges(g) == 3);
    }
  }
  create_all_direct_neighbour_named_edges_and_vertices_subgraphs_demo();
}
