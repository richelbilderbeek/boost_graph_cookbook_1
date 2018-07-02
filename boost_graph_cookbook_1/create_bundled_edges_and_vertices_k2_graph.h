#ifndef CREATE_BUNDLED_EDGES_AND_VERTICES_K2_GRAPH_H
#define CREATE_BUNDLED_EDGES_AND_VERTICES_K2_GRAPH_H

#include "create_empty_undirected_bundled_edges_and_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  my_bundled_vertex,
  my_bundled_edge
>
create_bundled_edges_and_vertices_k2_graph() noexcept;

#endif // CREATE_BUNDLED_EDGES_AND_VERTICES_K2_GRAPH_H
