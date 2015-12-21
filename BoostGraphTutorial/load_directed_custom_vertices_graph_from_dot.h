#ifndef LOAD_DIRECTED_CUSTOM_VERTICES_GRAPH_FROM_DOT_H
#define LOAD_DIRECTED_CUSTOM_VERTICES_GRAPH_FROM_DOT_H

#include <boost/graph/adjacency_list.hpp>
#include "install_vertex_custom_type.h"
#include "my_custom_vertex.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::property<
    boost::vertex_custom_type_t, my_custom_vertex
  >
>
load_directed_custom_vertices_graph_from_dot(
  const std::string& dot_filename
);

void load_directed_custom_vertices_graph_from_dot_test() noexcept;


#endif // LOAD_DIRECTED_CUSTOM_VERTICES_GRAPH_FROM_DOT_H
