#ifndef CREATE_BUNDLED_VERTICES_K2_GRAPH_H
#define CREATE_BUNDLED_VERTICES_K2_GRAPH_H

#include <boost/graph/adjacency_list.hpp>
#include "my_bundled_vertex.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  my_bundled_vertex
>
create_bundled_vertices_k2_graph() noexcept;

void create_bundled_vertices_k2_graph_test() noexcept;

#endif // CREATE_BUNDLED_VERTICES_K2_GRAPH_H
