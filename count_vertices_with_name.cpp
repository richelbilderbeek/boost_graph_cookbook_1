#include "count_vertices_with_name.h"

#include "count_vertices_with_name_demo.impl"

#include <cassert>

#include "create_empty_named_vertices_graph.h"
#include "add_named_vertex.h"

void count_vertices_with_name_test() noexcept
{
  {
    auto g = create_empty_named_vertices_graph();
    add_named_vertex("Rex", g);
    assert(count_vertices_with_name(g,"Rex") == 1);
    assert(count_vertices_with_name(g,"Nebular") == 0);
  }
  count_vertices_with_name_demo();
  std::cout << __func__ << ": OK" << '\n';
}
