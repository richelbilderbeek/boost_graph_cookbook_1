#ifndef LOAD_UNDIRECTED_CUSTOM_VERTICES_GRAPH_FROM_DOT_H
#define LOAD_UNDIRECTED_CUSTOM_VERTICES_GRAPH_FROM_DOT_H

#include "create_empty_undirected_custom_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<
    boost::vertex_custom_type_t, my_custom_vertex
  >
>
load_undirected_custom_vertices_graph_from_dot(
  const std::string& dot_filename
);

#endif // LOAD_UNDIRECTED_CUSTOM_VERTICES_GRAPH_FROM_DOT_H
