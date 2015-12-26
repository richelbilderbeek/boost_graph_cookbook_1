#ifndef CREATE_NASTY_DIRECTED_BUNDLED_VERTICES_GRAPH_H
#define CREATE_NASTY_DIRECTED_BUNDLED_VERTICES_GRAPH_H

#include "create_empty_directed_bundled_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  my_bundled_vertex
>
create_nasty_directed_bundled_vertices_graph() noexcept;

void create_nasty_directed_bundled_vertices_graph_test() noexcept;

#endif // CREATE_NASTY_DIRECTED_BUNDLED_VERTICES_GRAPH_H
