#include "save_graph_to_dot.h"

#include <iostream>
#include <sstream>

#include "save_graph_to_dot_demo.impl"
#include "copy_file.h"
#include "create_empty_directed_graph.h"
#include "create_empty_undirected_graph.h"
#include "create_k2_graph.h"
#include "create_named_vertices_k2_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"
#include "show_dot.h"
#include "convert_dot_to_svg.h"
#include "is_valid_dot_file.h"
#include "helper.h"

void save_graph_to_dot_test() noexcept
{
  
  //create_empty_directed_graph
  {
    const auto g = create_empty_directed_graph();
    const std::string base_filename{"save_graph_to_dot_test_empty_directed_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    save_graph_to_dot(g,dot_filename);
    assert(is_valid_dot_file(dot_filename));
    const std::vector<std::string> text{
      helper().file_to_vector(dot_filename)
    };
    const std::vector<std::string> expected_text{
      "digraph G {",
      "}"
    };
    assert(text == expected_text);
  }
  //create_empty_undirected_graph
  {
    const auto g = create_empty_undirected_graph();
    const std::string base_filename{"save_graph_to_dot_test_empty_undirected_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    save_graph_to_dot(g,dot_filename);
    assert(is_valid_dot_file(dot_filename));
    const std::vector<std::string> text{
      helper().file_to_vector(dot_filename)
    };
    const std::vector<std::string> expected_text{
      "graph G {",
      "}"
    };
    assert(text == expected_text);
  }
  //create_k2_graph
  {
    const auto g = create_k2_graph();
    const std::string base_filename{"save_graph_to_dot_test_k2_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    save_graph_to_dot(g,dot_filename);
    assert(is_valid_dot_file(dot_filename));
    const std::vector<std::string> text{
      helper().file_to_vector(dot_filename)
    };
    const std::vector<std::string> expected_text{
      "graph G {",
      "0;",
      "1;",
      "0--1 ;",
      "}"
    };
    assert(text == expected_text);
  }
  //Show it does not store the vertex names
  {
    const auto g = create_named_vertices_k2_graph();
    const std::string base_filename{"save_graph_to_dot_test_named_vertices_k2_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    save_graph_to_dot(g,dot_filename);
    assert(is_valid_dot_file(dot_filename));
    const std::vector<std::string> text{
      helper().file_to_vector(dot_filename)
    };
    const std::vector<std::string> expected_text{
      "graph G {",
      "0;",
      "1;",
      "0--1 ;",
      "}"
    };
    assert(text == expected_text);
  }

  save_graph_to_dot_demo();
  std::cout << __func__ << ": OK" << '\n';
}
