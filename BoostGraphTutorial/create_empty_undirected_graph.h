#ifndef CREATE_EMPTY_UNDIRECTED_GRAPH_H
#define CREATE_EMPTY_UNDIRECTED_GRAPH_H

#include <boost/graph/adjacency_list.hpp>
#include <initializer_list>

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS
>
create_empty_undirected_graph() noexcept;

#endif // CREATE_EMPTY_UNDIRECTED_GRAPH_H
