#include "add_custom_vertex.h"

#include "add_custom_vertex_demo.impl"

#include <cassert>
#include <iostream>

#include "create_empty_undirected_custom_vertices_graph.h"
#include "get_my_custom_vertexes.h"

void add_custom_vertex_test() noexcept
{
  //Add 1
  {
    auto g = create_empty_undirected_custom_vertices_graph();
    assert(boost::num_vertices(g) == 0);
    assert(boost::num_edges(g) == 0);
    const my_custom_vertex vertex("X");
    add_custom_vertex(vertex, g);
    assert(boost::num_vertices(g) == 1);
    assert(boost::num_edges(g) == 0);
    const std::vector<my_custom_vertex> vertices{get_my_custom_vertexes(g)};
    const std::vector<my_custom_vertex> expected_vertices{vertex};
    assert(vertices == expected_vertices);
  }
  //Add 2
  {
    auto g = create_empty_undirected_custom_vertices_graph();
    assert(boost::num_vertices(g) == 0);
    assert(boost::num_edges(g) == 0);
    const my_custom_vertex vertex_1("X");
    const my_custom_vertex vertex_2("Y");
    add_custom_vertex(vertex_1, g);
    add_custom_vertex(vertex_2, g);
    assert(boost::num_vertices(g) == 2);
    assert(boost::num_edges(g) == 0);
    const std::vector<my_custom_vertex> vertices{get_my_custom_vertexes(g)};
    const std::vector<my_custom_vertex> expected_vertices{vertex_1, vertex_2};
    assert(vertices == expected_vertices);
  }
  add_custom_vertex_demo();
  
}



