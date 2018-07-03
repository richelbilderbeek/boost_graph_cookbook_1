#ifndef CREATE_BUNDLED_EDGES_AND_VERTICES_PETERSEN_GRAPH_H
#define CREATE_BUNDLED_EDGES_AND_VERTICES_PETERSEN_GRAPH_H

#include "my_bundled_edge.h"
#include "my_bundled_vertex.h"
#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
  my_bundled_vertex, my_bundled_edge>
create_bundled_edges_and_vertices_petersen_graph();

#endif // CREATE_BUNDLED_EDGES_AND_VERTICES_PETERSEN_GRAPH_H
