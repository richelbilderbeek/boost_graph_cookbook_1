#include "create_empty_graph.h"

#include <iostream>

boost::adjacency_list<
  boost::listS,    // Store out-edges of each vertex in a std::list
  boost::vecS,     // Store vertices in a std::vector
  boost::directedS // The graph is directed
>
create_empty_graph() noexcept
{
  boost::adjacency_list<
    boost::listS,    // Store out-edges of each vertex in a std::list
    boost::vecS,     // Store vertices in a std::vector
    boost::directedS // The graph is directed
  > g;
  return g;
}

void test_create_empty_graph() noexcept
{
  const auto g = create_empty_graph();
  const auto edge_iters = boost::edges(g);
  assert(edge_iters.first == edge_iters.second);

  const auto vertex_iters = boost::vertices(g);
  assert(vertex_iters.first == vertex_iters.second);

  std::cout << __func__ << ": OK" << '\n';
}


