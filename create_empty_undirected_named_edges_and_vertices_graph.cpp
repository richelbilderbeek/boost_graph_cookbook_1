#include "create_empty_undirected_named_edges_and_vertices_graph.h"
#include "create_empty_undirected_named_edges_and_vertices_graph.impl"
#include "create_empty_undirected_named_edges_and_vertices_graph_demo.impl"

#include <cassert>
#include <iostream>
#include "add_named_edge.h"
#include "get_edge_names.h"
#include "get_vertex_names.h"
#include "create_empty_undirected_named_edges_and_vertices_graph.h"

void create_empty_undirected_named_edges_and_vertices_graph_test() noexcept
{
  {
    auto g = create_empty_undirected_named_edges_and_vertices_graph();
    add_named_edge("Eugene", g);
    const std::vector<std::string> expected_vertex_names{"",""};
    const std::vector<std::string> vertex_names = get_vertex_names(g);
    assert(expected_vertex_names == vertex_names);
    const std::vector<std::string> expected_edge_names{"Eugene"};
    const std::vector<std::string> edge_names = get_edge_names(g);
    assert(expected_edge_names == edge_names);
  }

  {
    const auto g = create_empty_undirected_named_edges_and_vertices_graph();
    assert(boost::num_edges(g) == 0);
    assert(boost::num_vertices(g) == 0);
    const std::vector<std::string> expected_vertex_names{};
    const std::vector<std::string> vertex_names = get_vertex_names(g);
    assert(expected_vertex_names == vertex_names);
    const std::vector<std::string> expected_edge_names{};
    const std::vector<std::string> edge_names = get_edge_names(g);
    assert(expected_edge_names == edge_names);
  }
  create_empty_undirected_named_edges_and_vertices_graph_demo();
  std::cout << __func__ << ": OK" << '\n';

}
