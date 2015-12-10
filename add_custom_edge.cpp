#include "add_custom_edge.h"

#include <cassert>
#include <iostream>

#include <boost/graph/adjacency_list.hpp>
#include "create_empty_custom_edges_and_vertices_graph.h"
#include "get_n_edges.h"
#include "get_n_vertices.h"

#include "get_edge_my_edges.h"

void add_custom_edge_test() noexcept
{
  //Add 1
  {
    auto g = create_empty_custom_edges_and_vertices_graph();
    assert(get_n_vertices(g) == 0);
    assert(get_n_edges(g) == 0);
    const my_edge edge("X");
    add_custom_edge(g,edge);
    assert(get_n_vertices(g) == 2);
    assert(get_n_edges(g) == 1);
    const std::vector<my_edge> edges{get_edge_my_edges(g)};
    const std::vector<my_edge> expected_edges{edge};
    assert(edges == expected_edges);
  }
  //Add 2
  {
    auto g = create_empty_custom_edges_and_vertices_graph();
    assert(get_n_vertices(g) == 0);
    assert(get_n_edges(g) == 0);
    const my_edge edge_1("X");
    const my_edge edge_2("Y");
    add_custom_edge(g,edge_1);
    add_custom_edge(g,edge_2);
    assert(get_n_vertices(g) == 4);
    assert(get_n_edges(g) == 2);
    const std::vector<my_edge> edges{get_edge_my_edges(g)};
    const std::vector<my_edge> expected_edges{edge_1, edge_2};
    assert(edges == expected_edges);
  }
  std::cout << __func__ << ": OK" << '\n';
}


