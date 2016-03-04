#include "get_vertex_selectedness.h"

#include "get_vertex_selectedness_demo.impl"

#include <cassert>
#include <iostream>
#include <boost/graph/properties.hpp>

#include "add_custom_and_selectable_vertex.h"
#include "create_empty_undirected_custom_and_selectable_edges_and_vertices_graph.h"
#include "get_vertex_selectedness.h"

void get_vertex_selectedness_test() noexcept
{
  {
    auto g
      = create_empty_undirected_custom_and_selectable_edges_and_vertices_graph();
    const auto vd
      = add_custom_and_selectable_vertex(my_custom_vertex(), false, g);
    assert(get_vertex_selectedness(vd, g) == false);
  }
  get_vertex_selectedness_demo();
  
}
