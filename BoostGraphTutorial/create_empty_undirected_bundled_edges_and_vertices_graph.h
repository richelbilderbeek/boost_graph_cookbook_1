#ifndef CREATE_EMPTY_UNDIRECTED_BUNDLED_EDGES_AND_VERTICES_GRAPH_H
#define CREATE_EMPTY_UNDIRECTED_BUNDLED_EDGES_AND_VERTICES_GRAPH_H

#include "my_bundled_edge.h"
#include "my_bundled_vertex.h"
#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  my_bundled_vertex,
  my_bundled_edge
>
create_empty_undirected_bundled_edges_and_vertices_graph() noexcept;

void create_empty_undirected_bundled_edges_and_vertices_graph_test() noexcept;

#endif // CREATE_EMPTY_UNDIRECTED_BUNDLED_EDGES_AND_VERTICES_GRAPH_H
