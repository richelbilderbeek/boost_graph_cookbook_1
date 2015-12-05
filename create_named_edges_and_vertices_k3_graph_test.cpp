#include "create_named_edges_and_vertices_k3_graph.h"

#include <cassert>
#include <iostream>
#include "get_n_edges.h"
#include "get_n_vertices.h"
#include "get_edge_names.h"
#include "get_vertex_names.h"
#include "print_vertex_names.h"

void create_named_edges_and_vertices_k3_graph_test() noexcept
{
  const auto g = create_named_edges_and_vertices_k3_graph();
  assert(get_n_edges(g) == 3);
  assert(get_n_vertices(g) == 3);
  const std::vector<std::string> expected_vertex_names{"top", "right", "left"};
  const std::vector<std::string> vertex_names = get_vertex_names(g);
  assert(expected_vertex_names == vertex_names);
  const std::vector<std::string> expected_edge_names{"AB", "BC", "CA"};
  const std::vector<std::string> edge_names = get_edge_names(g);
  assert(expected_edge_names == edge_names);
  std::cout << __func__ << ": OK" << '\n';

}
