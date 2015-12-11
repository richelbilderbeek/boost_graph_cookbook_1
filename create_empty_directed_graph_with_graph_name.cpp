#include "create_empty_directed_graph_with_graph_name.h"

#include "create_empty_directed_graph_with_graph_name.impl"

#include "create_empty_directed_graph_with_graph_name_demo.impl"

#include <cassert>
#include <iostream>

#include "get_n_edges.h"
#include "get_n_vertices.h"

void create_empty_directed_graph_with_graph_name_test() noexcept
{
  {
    auto g = create_empty_directed_graph_with_graph_name();
    assert(get_n_edges(g) == 0);
    assert(get_n_vertices(g) == 0);

  }
  create_empty_directed_graph_with_graph_name_demo();
  std::cout << __func__ << ": OK" << '\n';

}
