#include "find_first_edge_with_name.h"

#include "find_first_edge_with_name_demo.impl"

#include <cassert>

#include "create_named_edges_and_vertices_k3_graph.h"

void find_first_edge_with_name_test() noexcept
{
  {
    const auto g = create_named_edges_and_vertices_k3_graph();
    const auto ed = find_first_edge_with_name("AB", g);
    assert(boost::source(ed,g) != boost::target(ed,g));
  }

  find_first_edge_with_name_demo();
  std::cout << __func__ << ": OK" << '\n';
}

