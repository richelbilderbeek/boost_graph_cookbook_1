#include "create_bundled_vertices_k2_graph.h"

#include "create_bundled_vertices_k2_graph.impl"

#include "create_bundled_vertices_k2_graph_demo.impl"

#include <cassert>
#include <iostream>
#include "has_bundled_vertex_with_my_vertex.h"

void create_bundled_vertices_k2_graph_test() noexcept
{
  {
    const auto g = create_bundled_vertices_k2_graph();
    assert(boost::num_edges(g) == 1);
    assert(boost::num_vertices(g) == 2);
    assert(has_bundled_vertex_with_my_vertex(my_bundled_vertex("A", "source" ,0.0, 0.0), g));
    assert(has_bundled_vertex_with_my_vertex(my_bundled_vertex("B", "target" ,3.14, 3.14), g));
  }
  create_bundled_vertices_k2_graph_demo();
  std::cout << __func__ << ": OK" << '\n';

}
