#ifndef LOAD_UNDIRECTED_CUSTOM_EDGES_AND_VERTICES_GRAPH_FROM_DOT_H
#define LOAD_UNDIRECTED_CUSTOM_EDGES_AND_VERTICES_GRAPH_FROM_DOT_H

#include <boost/graph/adjacency_list.hpp>
#include "install_vertex_custom_type.h"
#include "install_edge_custom_type.h"
#include "my_vertex.h"
#include "my_edge.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<
    boost::vertex_custom_type_t, my_vertex
  >,
  boost::property<
    boost::edge_custom_type_t, my_edge
  >
>
load_undirected_custom_edges_and_vertices_graph_from_dot(
  const std::string& dot_filename
);

void load_undirected_custom_edges_and_vertices_graph_from_dot_test() noexcept;


#endif // LOAD_UNDIRECTED_CUSTOM_EDGES_AND_VERTICES_GRAPH_FROM_DOT_H
