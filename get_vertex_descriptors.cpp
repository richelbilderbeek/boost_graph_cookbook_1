#include "get_vertex_descriptors.h"

#include <iostream>

#include "create_empty_directed_graph.h"
#include "create_empty_undirected_graph.h"
#include "create_k2_graph.h"
#include "get_n_vertices.h"
#include "create_named_edges_and_vertices_k3_graph.h"

void get_vertex_descriptors_test() noexcept
{
  //Undirected K2 graph
  {
    const auto g = create_k2_graph();
    const auto vds = get_vertex_descriptors(g);
    assert(vds.size() == 2);
    assert(out_degree(vds[0], g) == 1);
    assert(out_degree(vds[1], g) == 1);
  }
  //Undirected K3 graph
  {
    const auto g = create_named_edges_and_vertices_k3_graph();
    const auto vds = get_vertex_descriptors(g);
    assert(vds.size() == 3);
    assert(out_degree(vds[0], g) == 2);
    assert(out_degree(vds[1], g) == 2);
    assert(out_degree(vds[2], g) == 2);
  }
  std::cout << __func__ << ": OK" << '\n';
}
