#ifndef LOAD_UNDIRECTED_BUNDLED_EDGES_AND_VERTICES_GRAPH_FROM_DOT_H
#define LOAD_UNDIRECTED_BUNDLED_EDGES_AND_VERTICES_GRAPH_FROM_DOT_H

#include <boost/graph/adjacency_list.hpp>
#include "my_bundled_vertex.h"
#include "my_bundled_edge.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  my_bundled_vertex,
  my_bundled_edge
>
load_undirected_bundled_edges_and_vertices_graph_from_dot(
  const std::string& dot_filename
);

void load_undirected_bundled_edges_and_vertices_graph_from_dot_test() noexcept;


#endif // LOAD_UNDIRECTED_BUNDLED_EDGES_AND_VERTICES_GRAPH_FROM_DOT_H
