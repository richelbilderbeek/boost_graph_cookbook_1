#ifndef CREATE_NASTY_UNDIRECTED_BUNDLED_EDGES_AND_VERTICES_GRAPH_H
#define CREATE_NASTY_UNDIRECTED_BUNDLED_EDGES_AND_VERTICES_GRAPH_H

#include "create_empty_undirected_bundled_edges_and_vertices_graph.h"

boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
  my_bundled_vertex, my_bundled_edge>
create_nasty_undirected_bundled_edges_and_vertices_graph();

#endif // CREATE_NASTY_UNDIRECTED_BUNDLED_EDGES_AND_VERTICES_GRAPH_H
