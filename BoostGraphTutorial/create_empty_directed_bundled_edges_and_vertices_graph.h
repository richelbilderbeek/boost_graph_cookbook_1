#ifndef CREATE_EMPTY_DIRECTED_BUNDLED_EDGES_AND_VERTICES_GRAPH_H
#define CREATE_EMPTY_DIRECTED_BUNDLED_EDGES_AND_VERTICES_GRAPH_H

#include <boost/graph/adjacency_list.hpp>
#include "my_bundled_edge.h"
#include "my_bundled_vertex.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  my_bundled_vertex,
  my_bundled_edge
>
create_empty_directed_bundled_edges_and_vertices_graph() noexcept;

void create_empty_directed_bundled_edges_and_vertices_graph_test() noexcept;

#endif // CREATE_EMPTY_DIRECTED_BUNDLED_EDGES_AND_VERTICES_GRAPH_H
