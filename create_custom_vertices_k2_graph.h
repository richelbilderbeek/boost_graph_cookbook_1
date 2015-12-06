#ifndef CREATE_CUSTOM_VERTICES_K2_GRAPH_H
#define CREATE_CUSTOM_VERTICES_K2_GRAPH_H

#include "install_vertex_custom_type.h"
#include "my_vertex.h"
#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<
    boost::vertex_custom_type_t,my_vertex
  >
>
create_custom_vertices_k2_graph() noexcept;

void create_custom_vertices_k2_graph_test() noexcept;

#endif // CREATE_CUSTOM_VERTICES_K2_GRAPH_H
