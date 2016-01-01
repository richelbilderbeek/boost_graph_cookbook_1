#include "add_custom_and_selectable_vertex.h"

#include "add_custom_and_selectable_vertex_demo.impl"

#include <cassert>
#include <iostream>

#include "create_empty_undirected_custom_and_selectable_vertices_graph.h"

void add_custom_and_selectable_vertex_test() noexcept
{
  //Add 1
  {
    auto g = create_empty_undirected_custom_and_selectable_vertices_graph();
    assert(boost::num_vertices(g) == 0);
    assert(boost::num_edges(g) == 0);
    const my_custom_vertex vertex("X");
    add_custom_and_selectable_vertex(vertex, true, g);
    assert(boost::num_vertices(g) == 1);
    assert(boost::num_edges(g) == 0);
  }
  //Add 2
  {
    auto g = create_empty_undirected_custom_and_selectable_vertices_graph();
    assert(boost::num_vertices(g) == 0);
    assert(boost::num_edges(g) == 0);
    const my_custom_vertex vertex_1("X");
    const my_custom_vertex vertex_2("Y");
    add_custom_and_selectable_vertex(vertex_1, true, g);
    add_custom_and_selectable_vertex(vertex_2, false, g);
    assert(boost::num_vertices(g) == 2);
    assert(boost::num_edges(g) == 0);
  }
  add_custom_and_selectable_vertex_demo();

}



