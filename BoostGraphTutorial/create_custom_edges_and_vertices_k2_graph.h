#ifndef CREATE_CUSTOM_EDGES_AND_VERTICES_K2_GRAPH_H
#define CREATE_CUSTOM_EDGES_AND_VERTICES_K2_GRAPH_H

#include "create_empty_undirected_custom_edges_and_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<
    boost::vertex_custom_type_t, my_custom_vertex
  >,
  boost::property<
    boost::edge_custom_type_t, my_custom_edge
  >
>
create_custom_edges_and_vertices_k2_graph() noexcept;

#endif // CREATE_CUSTOM_EDGES_AND_VERTICES_K2_GRAPH_H
