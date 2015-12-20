#include "add_named_edge.h"

#include "add_named_edge_demo.impl"

#include <cassert>
#include <iostream>

#include <boost/graph/adjacency_list.hpp>
#include "create_empty_undirected_named_edges_and_vertices_graph.h"


#include "get_edge_names.h"

void add_named_edge_test() noexcept
{
  //Add 1 edge
  {
    auto g = create_empty_undirected_named_edges_and_vertices_graph();
    assert(boost::num_vertices(g) == 0);
    assert(boost::num_edges(g) == 0);
    const std::string edge_name{"X"};
    add_named_edge(edge_name, g);
    assert(boost::num_vertices(g) == 2);
    assert(boost::num_edges(g) == 1);
    const std::vector<std::string> edge_names{get_edge_names(g)};
    const std::vector<std::string> expected_names{edge_name};
    assert(edge_names == expected_names);
  }
  //Add 2 edges
  {
    auto g = create_empty_undirected_named_edges_and_vertices_graph();
    assert(boost::num_vertices(g) == 0);
    assert(boost::num_edges(g) == 0);
    const std::string edge_name_1{"A"};
    const std::string edge_name_2{"B"};
    add_named_edge(edge_name_1, g);
    add_named_edge(edge_name_2, g);
    assert(boost::num_vertices(g) == 4);
    assert(boost::num_edges(g) == 2);
    const std::vector<std::string> edge_names{get_edge_names(g)};
    const std::vector<std::string> expected_names{edge_name_1,edge_name_2};
    assert(edge_names == expected_names);
  }
  add_named_edge_demo();
  std::cout << __func__ << ": OK" << '\n';
}
