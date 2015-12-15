#include "get_first_vertex_with_name_out_degree.h"

#include "get_first_vertex_with_name_out_degree_demo.impl"

#include <cassert>
#include <iostream>

#include "create_named_vertices_k2_graph.h"

void get_first_vertex_with_name_out_degree_test() noexcept
{
  {
    const auto g = create_named_vertices_k2_graph();
    assert(get_first_vertex_with_name_out_degree("A", g) == 1);
    assert(get_first_vertex_with_name_out_degree("B", g) == 1);
  }
  get_first_vertex_with_name_out_degree_demo();
  std::cout << __func__ << ": OK" << '\n';
}
