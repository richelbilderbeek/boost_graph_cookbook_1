#include "has_bundled_edge_with_my_edge.h"

#include "has_bundled_edge_with_my_edge_demo.impl"

#include <cassert>
#include <iostream>

#include "add_bundled_edge.h"
#include "create_bundled_edges_and_vertices_k3_graph.h"

void has_bundled_edge_with_my_edge_test() noexcept
{
  {
    auto g
      = create_bundled_edges_and_vertices_k3_graph();
    assert(
      has_bundled_edge_with_my_edge(
        my_bundled_edge("Oxygen","Air",1.0,2.0),g
      )
    );
  }
  has_bundled_edge_with_my_edge_demo();

}
