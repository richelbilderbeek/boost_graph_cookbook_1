#include "create_empty_undirected_graph_with_graph_name.h"

#include "create_empty_undirected_graph_with_graph_name.impl"

#include "create_empty_undirected_graph_with_graph_name_demo.impl"

#include <cassert>
#include <iostream>




void create_empty_undirected_graph_with_graph_name_test() noexcept
{
  {
    auto g = create_empty_undirected_graph_with_graph_name();
    assert(boost::num_edges(g) == 0);
    assert(boost::num_vertices(g) == 0);

  }
  create_empty_undirected_graph_with_graph_name_demo();
  std::cout << __func__ << ": OK" << '\n';

}
