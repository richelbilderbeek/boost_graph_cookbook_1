#include "get_n_edges.h"

#include <iostream>

#include "create_empty_graph.h"

void test_get_n_edges() noexcept
{
  const auto g = create_empty_graph();
  assert(get_n_edges(g) == 0);

  std::cout << __func__ << ": OK" << '\n';
}

