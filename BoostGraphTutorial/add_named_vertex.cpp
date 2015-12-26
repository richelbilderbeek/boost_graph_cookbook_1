#include "add_named_vertex.h"

#include "add_named_vertex_demo.impl"

#include <cassert>
#include <iostream>

#include "create_empty_undirected_named_vertices_graph.h"


#include "get_vertex_names.h"
#include "get_vertex_descriptors.h"
#include "get_edge_descriptors.h"

void add_named_vertex_test() noexcept
{
  //Add 1
  {
    auto g = create_empty_undirected_named_vertices_graph();
    assert(get_vertex_descriptors(g).size() == 0);
    assert(get_edge_descriptors(g).size() == 0);
    assert(boost::num_vertices(g) == 0);
    assert(boost::num_edges(g) == 0);
    const std::string vertex_name{"X"};
    add_named_vertex(vertex_name, g);
    assert(get_vertex_descriptors(g).size() == 1);
    assert(get_edge_descriptors(g).size() == 0);
    assert(boost::num_vertices(g) == 1);
    assert(boost::num_edges(g) == 0);
    const std::vector<std::string> vertex_names{get_vertex_names(g)};
    const std::vector<std::string> expected_names{vertex_name};
    assert(vertex_names == expected_names);
  }
  //Add 2
  {
    auto g = create_empty_undirected_named_vertices_graph();
    assert(boost::num_vertices(g) == 0);
    assert(boost::num_edges(g) == 0);
    const std::string vertex_name_1{"A"};
    const std::string vertex_name_2{"B"};
    add_named_vertex(vertex_name_1, g);
    add_named_vertex(vertex_name_2, g);
    assert(boost::num_vertices(g) == 2);
    assert(boost::num_edges(g) == 0);
    const std::vector<std::string> vertex_names{get_vertex_names(g)};
    const std::vector<std::string> expected_names{vertex_name_1,vertex_name_2};
    assert(vertex_names == expected_names);
  }
  add_named_vertex_demo();
  std::cout << __func__ << ": OK" << '\n';
}

