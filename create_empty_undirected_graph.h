#ifndef CREATE_EMPTY_UNDIRECTED_GRAPH_H
#define CREATE_EMPTY_UNDIRECTED_GRAPH_H

#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS
> create_empty_undirected_graph() noexcept;

void create_empty_undirected_graph_test() noexcept;

#endif // CREATE_EMPTY_UNDIRECTED_GRAPH_H
