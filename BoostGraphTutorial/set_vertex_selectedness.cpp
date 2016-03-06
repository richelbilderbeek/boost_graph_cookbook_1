#include "set_vertex_selectedness.h"

#include "set_vertex_selectedness_demo.impl"

#include <iostream>
#include <cassert>

#include "create_empty_undirected_custom_edges_and_vertices_graph.h"
#include "add_custom_edge.h"
#include "find_first_custom_edge_with_my_edge.h"

void set_vertex_selectedness_test() noexcept
{
  {
    auto g
      = create_empty_undirected_custom_and_selectable_edges_and_vertices_graph();
    const auto vd = add_custom_and_selectable_vertex(
      my_custom_vertex(), true, g
    );
    assert(get_vertex_selectedness(vd, g) == true);
    set_vertex_selectedness(false, vd, g);
    assert(get_vertex_selectedness(vd, g) == false);
    set_vertex_selectedness(true, vd, g);
    assert(get_vertex_selectedness(vd, g) == true);
  }
  set_vertex_selectedness_demo();
  
}
