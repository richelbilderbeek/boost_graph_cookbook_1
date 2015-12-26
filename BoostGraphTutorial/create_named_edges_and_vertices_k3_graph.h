#ifndef CREATE_NAMED_EDGES_AND_VERTICES_K3_GRAPH_H
#define CREATE_NAMED_EDGES_AND_VERTICES_K3_GRAPH_H

#include "create_empty_undirected_named_edges_and_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<boost::vertex_name_t,std::string>,
  boost::property<boost::edge_name_t,std::string>
>
create_named_edges_and_vertices_k3_graph() noexcept;

void create_named_edges_and_vertices_k3_graph_test() noexcept;

#endif // CREATE_NAMED_EDGES_AND_VERTICES_K3_GRAPH_H
