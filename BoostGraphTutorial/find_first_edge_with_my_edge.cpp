#include "find_first_edge_with_my_edge.h"

#include "find_first_edge_with_my_edge_demo.impl"

#include <cassert>

#include "create_custom_edges_and_vertices_k3_graph.h"

void find_first_edge_with_my_edge_test() noexcept
{
  {
    const auto g = create_custom_edges_and_vertices_k3_graph();
    const auto ed = find_first_edge_with_my_edge(
      my_custom_edge("AB","first",0.0,0.0),
      g
    );
    assert(boost::source(ed,g) != boost::target(ed,g));
  }

  find_first_edge_with_my_edge_demo();
  std::cout << __func__ << ": OK" << '\n';
}

