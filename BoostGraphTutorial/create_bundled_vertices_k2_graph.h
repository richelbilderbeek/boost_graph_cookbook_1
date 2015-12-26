#ifndef CREATE_BUNDLED_VERTICES_K2_GRAPH_H
#define CREATE_BUNDLED_VERTICES_K2_GRAPH_H

#include "create_empty_undirected_bundled_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  my_bundled_vertex
>
create_bundled_vertices_k2_graph() noexcept;

void create_bundled_vertices_k2_graph_test() noexcept;

#endif // CREATE_BUNDLED_VERTICES_K2_GRAPH_H
