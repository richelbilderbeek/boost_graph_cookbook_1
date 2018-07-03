#ifndef CREATE_NAMED_VERTICES_K3_GRAPH_H
#define CREATE_NAMED_VERTICES_K3_GRAPH_H

#include "create_empty_undirected_text_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<boost::vertex_name_t,std::string>
>
create_text_vertices_k3_graph() noexcept;

#endif // CREATE_NAMED_VERTICES_K3_GRAPH_H
