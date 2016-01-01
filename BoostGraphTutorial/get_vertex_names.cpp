#include "get_vertex_names.h"

#include "get_vertex_names_demo.impl"

#include <cassert>
#include <iostream>


#include "create_k2_graph.h"
#include "add_named_vertex.h"
#include "create_empty_undirected_named_vertices_graph.h"
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
    auto g = create_empty_undirected_named_vertices_graph();
    const std::string vertex_name_1{"Chip"};
    const std::string vertex_name_2{"Chap"};
    add_named_vertex(vertex_name_1, g);
    add_named_vertex(vertex_name_2, g);
    const std::vector<std::string> expected_names{vertex_name_1, vertex_name_2};
    const std::vector<std::string> vertex_names{get_vertex_names(g)};
    assert(expected_names == vertex_names);
  }
  //Named K2 graph
  {
    const auto g = create_named_vertices_k2_graph();
    const std::vector<std::string> expected_names{"Me", "My computer"};
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
  get_vertex_names_demo();
  
}
