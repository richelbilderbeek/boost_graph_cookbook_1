#include "create_empty_undirected_named_vertices_graph.h"

#include "create_empty_undirected_named_vertices_graph.impl"

#include "create_empty_undirected_named_vertices_graph.h"

#include "create_empty_undirected_named_vertices_graph_demo.impl"

#include <cassert>
#include <iostream>

#include "get_n_edges.h"
#include "get_n_vertices.h"
#include "get_edges.h"
#include "get_vertices.h"
#include "get_edge_descriptors.h"
#include "get_vertex_descriptors.h"

void create_empty_undirected_named_vertices_graph_test() noexcept
{
  const auto g = create_empty_undirected_named_vertices_graph();
  const auto vip = get_vertices(g);
  assert(vip.first == vip.second);
  const auto vds = get_vertex_descriptors(g);
  assert(vds.empty());
  const auto eip = get_edges(g);
  assert(eip.first == eip.second);
  const auto eds = get_edge_descriptors(g);
  assert(eds.empty());

  assert(get_n_edges(g) == 0);
  assert(get_n_vertices(g) == 0);

  //Sure, can
  //add_vertex(g);

  create_empty_undirected_named_vertices_graph_demo();
  std::cout << __func__ << ": OK" << '\n';
}
