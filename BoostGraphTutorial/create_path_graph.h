#ifndef CREATE_PATH_GRAPH_H
#define CREATE_PATH_GRAPH_H

#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS
>
create_path_graph(const int n_vertices) noexcept;

#endif // CREATE_PATH_GRAPH_H
