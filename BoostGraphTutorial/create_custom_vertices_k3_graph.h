#ifndef CREATE_CUSTOM_VERTICES_K3_GRAPH_H
#define CREATE_CUSTOM_VERTICES_K3_GRAPH_H

#include "create_empty_undirected_custom_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<
    boost::vertex_custom_type_t, my_custom_vertex
  >
>
create_custom_vertices_k3_graph() noexcept;

void create_custom_vertices_k3_graph_test() noexcept;

#endif // CREATE_CUSTOM_VERTICES_K3_GRAPH_H
