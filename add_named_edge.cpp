#include "add_named_edge.h"

#include "add_named_edge_demo.impl"

#include <cassert>
#include <iostream>

#include <boost/graph/adjacency_list.hpp>
#include "create_empty_named_edges_and_vertices_graph.h"
#include "get_n_edges.h"
#include "get_n_vertices.h"
#include "get_edge_names.h"

void add_named_edge_test() noexcept
{
  //Add 1 edge
  {
    auto g = create_empty_named_edges_and_vertices_graph();
    assert(get_n_vertices(g) == 0);
    assert(get_n_edges(g) == 0);
    const std::string edge_name{"X"};
    add_named_edge(g,edge_name);
    assert(get_n_vertices(g) == 2);
    assert(get_n_edges(g) == 1);
    const std::vector<std::string> edge_names{get_edge_names(g)};
    const std::vector<std::string> expected_names{edge_name};
    assert(edge_names == expected_names);
  }
  //Add 2 edges
  {
    auto g = create_empty_named_edges_and_vertices_graph();
    assert(get_n_vertices(g) == 0);
    assert(get_n_edges(g) == 0);
    const std::string edge_name_1{"A"};
    const std::string edge_name_2{"B"};
    add_named_edge(g,edge_name_1);
    add_named_edge(g,edge_name_2);
    assert(get_n_vertices(g) == 4);
    assert(get_n_edges(g) == 2);
    const std::vector<std::string> edge_names{get_edge_names(g)};
    const std::vector<std::string> expected_names{edge_name_1,edge_name_2};
    assert(edge_names == expected_names);
  }
  add_named_edge_demo();
  std::cout << __func__ << ": OK" << '\n';
}
