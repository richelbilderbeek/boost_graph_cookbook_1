#ifndef LOAD_DIRECTED_GRAPH_FROM_DOT_H
#define LOAD_DIRECTED_GRAPH_FROM_DOT_H

#include "create_empty_directed_graph.h"

boost::adjacency_list<>
load_directed_graph_from_dot(
  const std::string& dot_filename
);

void load_directed_graph_from_dot_test() noexcept;

#endif // LOAD_DIRECTED_GRAPH_FROM_DOT_H
