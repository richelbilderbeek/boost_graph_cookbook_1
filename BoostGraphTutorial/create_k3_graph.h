#ifndef CREATE_K3_GRAPH_H
#define CREATE_K3_GRAPH_H

#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS
>
create_k3_graph() noexcept;

void create_k3_graph_test() noexcept;

#endif // CREATE_K3_GRAPH_H
