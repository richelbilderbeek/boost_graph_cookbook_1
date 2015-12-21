#ifndef CREATE_EMPTY_DIRECTED_BUNDLED_VERTICES_GRAPH_H
#define CREATE_EMPTY_DIRECTED_BUNDLED_VERTICES_GRAPH_H

#include "my_bundled_vertex.h"
#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  my_bundled_vertex
>
create_empty_directed_bundled_vertices_graph() noexcept;

void create_empty_directed_bundled_vertices_graph_test() noexcept;

#endif // CREATE_EMPTY_DIRECTED_BUNDLED_VERTICES_GRAPH_H
