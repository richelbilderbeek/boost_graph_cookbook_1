#include "get_n_edges.h"

#include <iostream>

#include "create_empty_graph.h"
#include "create_k2_graph.h"

void get_n_edges_test() noexcept
{
  {
    const auto g = create_empty_directed_graph();
    assert(get_n_edges(g) == 0);
  }
  {
    const auto g = create_k2_graph();
    assert(get_n_edges(g) == 1);
  }

  std::cout << __func__ << ": OK" << '\n';
}

