#ifndef LOAD_UNDIRECTED_BUNDLED_VERTICES_GRAPH_FROM_DOT_H
#define LOAD_UNDIRECTED_BUNDLED_VERTICES_GRAPH_FROM_DOT_H

#include "create_empty_undirected_bundled_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  my_bundled_vertex
>
load_undirected_bundled_vertices_graph_from_dot(
  const std::string& dot_filename
);

void load_undirected_bundled_vertices_graph_from_dot_test() noexcept;


#endif // LOAD_UNDIRECTED_BUNDLED_VERTICES_GRAPH_FROM_DOT_H
