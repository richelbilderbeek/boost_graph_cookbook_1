#include "has_vertex_with_name.h"

#include "has_vertex_with_name_demo.impl"

#include <cassert>
#include <iostream>

#include "add_named_vertex.h"
#include "create_empty_undirected_named_vertices_graph.h"

void has_vertex_with_name_test() noexcept
{
  {
    auto g = create_empty_undirected_named_vertices_graph();
    assert(!has_vertex_with_name("Felix",g));
    add_named_vertex("Felix",g);
    assert(has_vertex_with_name("Felix",g));
  }
  {
    auto g = create_empty_undirected_named_vertices_graph<int>();
    assert(!has_vertex_with_name(42,g));
    add_named_vertex(42,g);
    assert(has_vertex_with_name(42,g));
  }

  has_vertex_with_name_demo();
  std::cout << __func__ << ": OK" << std::endl;
}
