#include "find_first_vertex_with_my_vertex.h"

#include "find_first_vertex_with_my_vertex_demo.impl"

#include <cassert>

#include "create_custom_vertices_k2_graph.h"

void find_first_vertex_with_my_vertex_test() noexcept
{
  {
    const auto g = create_custom_vertices_k2_graph();
    assert(has_vertex_with_my_vertex(my_vertex("from","source",0.0,0.0), g));
    const auto vd = find_first_vertex_with_my_vertex(my_vertex("from","source",0.0,0.0), g);
    assert(boost::out_degree(vd,g) == 1);
    assert(boost::in_degree(vd,g) == 1);
  }

  find_first_vertex_with_my_vertex_demo();
  std::cout << __func__ << ": OK" << '\n';
}

