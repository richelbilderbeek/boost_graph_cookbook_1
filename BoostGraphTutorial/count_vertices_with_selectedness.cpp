#include "count_vertices_with_selectedness.h"

#include "count_vertices_with_selectedness_demo.impl"

#include <cassert>
#include <iostream>

#include "create_empty_undirected_custom_and_selectable_vertices_graph.h"
#include "add_custom_and_selectable_vertex.h"

void count_vertices_with_selectedness_test() noexcept
{
  {
    auto g = create_empty_undirected_custom_and_selectable_vertices_graph();
    add_custom_and_selectable_vertex(
      my_custom_vertex("A"), true, g
    );
    add_custom_and_selectable_vertex(
      my_custom_vertex("B"), false, g
    );
    add_custom_and_selectable_vertex(
      my_custom_vertex("C"), true, g
    );
    assert(count_vertices_with_selectedness( true, g) == 2);
    assert(count_vertices_with_selectedness(false, g) == 1);
  }
  count_vertices_with_selectedness_demo();
  
}
