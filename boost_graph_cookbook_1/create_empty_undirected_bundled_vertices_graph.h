#ifndef CREATE_EMPTY_UNDIRECTED_BUNDLED_VERTICES_GRAPH_H
#define CREATE_EMPTY_UNDIRECTED_BUNDLED_VERTICES_GRAPH_H

#include "my_bundled_vertex.h"
#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
  my_bundled_vertex>
create_empty_undirected_bundled_vertices_graph() noexcept;

#endif // CREATE_EMPTY_UNDIRECTED_BUNDLED_VERTICES_GRAPH_H
