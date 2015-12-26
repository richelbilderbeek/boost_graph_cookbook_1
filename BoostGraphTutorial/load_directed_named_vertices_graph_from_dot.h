#ifndef LOAD_DIRECTED_NAMED_VERTICES_GRAPH_FROM_DOT_H
#define LOAD_DIRECTED_NAMED_VERTICES_GRAPH_FROM_DOT_H

#include "create_empty_directed_named_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::property<
    boost::vertex_name_t,std::string
  >
>
load_directed_named_vertices_graph_from_dot(
  const std::string& dot_filename
);

void load_directed_named_vertices_graph_from_dot_test() noexcept;


#endif // LOAD_DIRECTED_NAMED_VERTICES_GRAPH_FROM_DOT_H
