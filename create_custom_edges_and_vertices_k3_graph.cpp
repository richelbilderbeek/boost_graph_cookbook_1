#include "create_custom_edges_and_vertices_k3_graph.h"

#include "create_custom_edges_and_vertices_k3_graph.impl"

#include <cassert>
#include <iostream>
#include "get_n_edges.h"
#include "get_n_vertices.h"
#include "add_custom_edge.h"
#include "add_custom_vertex.h"

void create_custom_edges_and_vertices_k3_graph_test() noexcept
{
  auto g = create_custom_edges_and_vertices_k3_graph();
  assert(get_n_edges(g) == 3);
  assert(get_n_vertices(g) == 3);
  add_custom_vertex(g,my_vertex("v"));
  assert(get_n_edges(g) == 3);
  assert(get_n_vertices(g) == 4);
  add_custom_edge(g,my_edge("e"));
  assert(get_n_edges(g) == 4);
  assert(get_n_vertices(g) == 6);
  std::cout << __func__ << ": OK" << '\n';

}
