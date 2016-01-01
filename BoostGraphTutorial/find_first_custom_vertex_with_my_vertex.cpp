#include "find_first_custom_vertex_with_my_vertex.h"

#include "find_first_custom_vertex_with_my_vertex_demo.impl"

#include <iostream>
#include <cassert>

#include "create_custom_vertices_k2_graph.h"

void find_first_custom_vertex_with_my_vertex_test() noexcept
{
  {
    const auto g = create_custom_vertices_k2_graph();
    assert(has_custom_vertex_with_my_custom_vertex(my_custom_vertex("A","source",0.0,0.0), g));
    const auto vd = find_first_custom_vertex_with_my_vertex(my_custom_vertex("A","source",0.0,0.0), g);
    assert(out_degree(vd,g) == 1); //not boost::out_degree
    assert(in_degree(vd,g) == 1); //not boost::in_degree
  }

  find_first_custom_vertex_with_my_vertex_demo();
  
}

