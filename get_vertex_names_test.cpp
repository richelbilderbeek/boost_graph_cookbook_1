#include "get_vertex_names_test.h"

#include <cassert>
#include <iostream>
#include "get_n_edges.h"
#include "get_n_vertices.h"
#include "get_vertex_names.h"
#include "create_k2_graph.h"
#include "create_named_vertices_k2_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"

void get_vertex_names_test() noexcept
{
  //Unnamed K2 graph: should not compile, and it doesn't :-)
  {
    //get_vertex_names(create_k2_graph());
  }
  //Named K2 graph
  {
    const auto g = create_named_vertices_k2_graph();
    const std::vector<std::string> expected_names{"from", "to"};
    const std::vector<std::string> vertex_names{get_vertex_names(g)};
    assert(expected_names == vertex_names);
  }
  //Named K3 graph
  {
    const auto g = create_named_edges_and_vertices_k3_graph();
    const std::vector<std::string> expected_names{"top", "right", "left"};
    const std::vector<std::string> vertex_names{get_vertex_names(g)};
    assert(expected_names == vertex_names);
  }
  std::cout << __func__ << ": OK" << '\n';
}
