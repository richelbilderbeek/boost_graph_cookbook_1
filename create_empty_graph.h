#ifndef CREATE_EMPTY_GRAPH_H
#define CREATE_EMPTY_GRAPH_H

#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<
  boost::listS,    // Store out-edges of each vertex in a std::list
  boost::vecS,     // Store vertices in a std::vector
  boost::directedS // The graph is directed
>
create_empty_graph() noexcept;

void test_create_empty_graph() noexcept;

#endif // CREATE_EMPTY_GRAPH_H
