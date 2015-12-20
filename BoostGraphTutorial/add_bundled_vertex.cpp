#include "add_bundled_vertex.h"

#include <cassert>
#include <iostream>

#include <boost/graph/adjacency_list.hpp>
#include "create_empty_undirected_bundled_vertices_graph.h"

#include "get_custom_vertex_my_vertexes.h"

void add_bundled_vertex_test() noexcept
{
  //Add 1
  {
    auto g = create_empty_undirected_bundled_vertices_graph();
    assert(boost::num_vertices(g) == 0);
    assert(boost::num_edges(g) == 0);
    const my_vertex vertex("X");
    add_bundled_vertex(vertex, g);
    assert(boost::num_vertices(g) == 1);
    assert(boost::num_edges(g) == 0);
  }
  //Add 2
  {
    auto g = create_empty_undirected_bundled_vertices_graph();
    assert(boost::num_vertices(g) == 0);
    assert(boost::num_edges(g) == 0);
    const my_vertex vertex_1("X");
    const my_vertex vertex_2("Y");
    add_bundled_vertex(vertex_1, g);
    add_bundled_vertex(vertex_2, g);
    assert(boost::num_vertices(g) == 2);
    assert(boost::num_edges(g) == 0);
  }
  std::cout << __func__ << ": OK" << '\n';
}



