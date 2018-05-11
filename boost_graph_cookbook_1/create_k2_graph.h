#ifndef CREATE_K2_GRAPH_H
#define CREATE_K2_GRAPH_H

#include "create_empty_undirected_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS
>
create_k2_graph() noexcept;

#endif // CREATE_K2_GRAPH_H
