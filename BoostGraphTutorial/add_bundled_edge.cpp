#include "add_bundled_edge.h"

#include "add_bundled_edge_demo.impl"

#include <cassert>
#include <iostream>

#include "create_empty_undirected_bundled_edges_and_vertices_graph.h"

#include "get_my_bundled_edges.h"
#include "get_my_custom_edges.h"

void add_bundled_edge_test() noexcept
{
  //Add 1
  {
    auto g = create_empty_undirected_bundled_edges_and_vertices_graph();
    assert(boost::num_vertices(g) == 0);
    assert(boost::num_edges(g) == 0);
    const my_bundled_edge edge("X");
    add_bundled_edge(edge, g);
    assert(boost::num_vertices(g) == 2);
    assert(boost::num_edges(g) == 1);
    const std::vector<my_bundled_edge> edges{get_my_bundled_edges(g)};
    const std::vector<my_bundled_edge> expected_edges{edge};
    assert(edges == expected_edges);
  }
  //Add 2
  {
    auto g = create_empty_undirected_bundled_edges_and_vertices_graph();
    assert(boost::num_vertices(g) == 0);
    assert(boost::num_edges(g) == 0);
    const my_bundled_edge edge_1("X");
    const my_bundled_edge edge_2("Y");
    add_bundled_edge(edge_1, g);
    add_bundled_edge(edge_2, g);
    assert(boost::num_vertices(g) == 4);
    assert(boost::num_edges(g) == 2);
    const std::vector<my_bundled_edge> edges{get_my_bundled_edges(g)};
    const std::vector<my_bundled_edge> expected_edges{edge_1, edge_2};
    assert(edges == expected_edges);
  }
  add_bundled_edge_demo();
  std::cout << __func__ << ": OK" << '\n';
}



