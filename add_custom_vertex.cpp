#include "add_custom_vertex.h"

#include <cassert>
#include <iostream>

#include <boost/graph/adjacency_list.hpp>
#include "create_empty_custom_vertices_graph.h"
#include "get_n_edges.h"
#include "get_n_vertices.h"

#ifdef TODO_1
#include "get_custom_vertices.h"
#endif

void add_custom_vertex_test() noexcept
{
  //Add 1
  {
    auto g = create_empty_custom_vertices_graph();
    assert(get_n_vertices(g) == 0);
    assert(get_n_edges(g) == 0);
    const my_vertex vertex("X");
    add_custom_vertex(g,vertex);
    assert(get_n_vertices(g) == 1);
    assert(get_n_edges(g) == 0);
    #ifdef TODO_1
    const std::vector<my_vertex> vertices{get_custom_vertices(g)};
    const std::vector<my_vertex> expected_vertices{vertex};
    assert(vertices == expected_vertices);
    #else
    std::cout << __func__ << ": TODO #1" << '\n';
    #endif
  }
  //Add 2
  {
    auto g = create_empty_custom_vertices_graph();
    assert(get_n_vertices(g) == 0);
    assert(get_n_edges(g) == 0);
    const my_vertex vertex_1("X");
    const my_vertex vertex_2("X");
    add_custom_vertex(g,vertex_1);
    add_custom_vertex(g,vertex_2);
    assert(get_n_vertices(g) == 2);
    assert(get_n_edges(g) == 0);
    #ifdef TODO_1
    const std::vector<my_vertex> vertices{get_custom_vertices(g)};
    const std::vector<my_vertex> expected_vertices{vertex_1, vertex_2};
    assert(vertices == expected_vertices);
    #endif
  }
  std::cout << __func__ << ": OK" << '\n';
}



