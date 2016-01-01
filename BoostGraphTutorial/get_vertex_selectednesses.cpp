#include "get_vertex_selectednesses.h"

#include "get_vertex_selectednesses_demo.impl"

#include <cassert>
#include <iostream>


#include "create_k2_graph.h"
#include "add_named_vertex.h"
#include "create_empty_undirected_named_vertices_graph.h"
#include "create_named_vertices_k2_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"

void get_vertex_selectednesses_test() noexcept
{
  //Named K2 graph
  {
    auto g = create_empty_undirected_custom_and_selectable_vertices_graph();
    add_custom_and_selectable_vertex(my_custom_vertex{"Chip"},true,g);
    add_custom_and_selectable_vertex(my_custom_vertex{"Chip"},false,g);
    const std::vector<bool> expected_selectednesses{true, false};
    const std::vector<bool> vertex_selectednesses{get_vertex_selectednesses(g)};
    assert(expected_selectednesses == vertex_selectednesses);
  }
  get_vertex_selectednesses_demo();
  
}
