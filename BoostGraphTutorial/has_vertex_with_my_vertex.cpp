#include "has_vertex_with_my_vertex.h"

#include "has_vertex_with_my_vertex_demo.impl"

#include <cassert>
#include <iostream>

#include "add_named_vertex.h"
#include "create_empty_undirected_named_vertices_graph.h"

void has_vertex_with_my_vertex_test() noexcept
{
  {
    auto g
      = create_empty_undirected_custom_vertices_graph();
    const my_custom_vertex v("Felix");
    assert(!has_vertex_with_my_vertex(v,g));
    add_custom_vertex(v,g);
    assert(has_vertex_with_my_vertex(v,g));
  }
  has_vertex_with_my_vertex_demo();

}
