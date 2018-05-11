#ifndef CREATE_CUSTOM_VERTICES_PETERSEN_GRAPH_H
#define CREATE_CUSTOM_VERTICES_PETERSEN_GRAPH_H

#include <boost/graph/adjacency_list.hpp>
#include "install_vertex_custom_type.h"
#include "my_custom_vertex.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<
    boost::vertex_custom_type_t, my_custom_vertex
  >
>
create_custom_vertices_petersen_graph() noexcept;

#endif // CREATE_CUSTOM_VERTICES_PETERSEN_GRAPH_H
