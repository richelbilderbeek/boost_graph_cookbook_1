#ifndef CREATE_EMPTY_UNDIRECTED_CUSTOM_EDGES_AND_VERTICES_GRAPH_H
#define CREATE_EMPTY_UNDIRECTED_CUSTOM_EDGES_AND_VERTICES_GRAPH_H

#include "install_edge_custom_type.h"
#include "install_vertex_custom_type.h"
#include "my_custom_vertex.h"
#include "my_custom_edge.h"
#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<
    boost::vertex_custom_type_t, my_custom_vertex
  >,
  boost::property<
    boost::edge_custom_type_t,my_custom_edge
  >
>
create_empty_undirected_custom_edges_and_vertices_graph() noexcept;

void create_empty_undirected_custom_edges_and_vertices_graph_test() noexcept;

#endif // CREATE_EMPTY_UNDIRECTED_CUSTOM_EDGES_AND_VERTICES_GRAPH_H
