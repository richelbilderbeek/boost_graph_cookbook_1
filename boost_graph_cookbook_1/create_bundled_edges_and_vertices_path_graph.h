#ifndef CREATE_BUNDLED_EDGES_AND_VERTICES_PATH_GRAPH_H
#define CREATE_BUNDLED_EDGES_AND_VERTICES_PATH_GRAPH_H

#include <vector>
#include <boost/graph/adjacency_list.hpp>
#include "my_bundled_edge.h"
#include "my_bundled_vertex.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  my_bundled_vertex,
  my_bundled_edge
>
create_bundled_edges_and_vertices_path_graph(
  const std::vector<my_bundled_edge>& edges,
  const std::vector<my_bundled_vertex>& vertices
);

#endif // CREATE_BUNDLED_EDGES_AND_VERTICES_PATH_GRAPH_H
