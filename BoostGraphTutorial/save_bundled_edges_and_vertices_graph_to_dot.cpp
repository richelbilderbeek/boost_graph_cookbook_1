#include "save_bundled_edges_and_vertices_graph_to_dot.h"

#include "save_bundled_edges_and_vertices_graph_to_dot_demo.impl"

#include <cassert>
#include <iostream>
#include <sstream>

#include "copy_file.h"
#include "create_bundled_edges_and_vertices_k3_graph.h"
#include "show_dot.h"
#include "convert_dot_to_svg.h"
#include "helper.h"
#include "is_regular_file.h"

void save_bundled_edges_and_vertices_graph_to_dot_test() noexcept
{
  //Show how it stores the create_bundled_edges_and_vertices_k3_graph
  {
    const auto g = create_bundled_edges_and_vertices_k3_graph();

    const std::string base_filename{"create_bundled_edges_and_vertices_k3_graph"};
    const std::string dot_filename{base_filename + ".dot"};

    save_bundled_edges_and_vertices_graph_to_dot(g,dot_filename);
    assert(is_regular_file(dot_filename));
    const std::vector<std::string> text{
      helper().file_to_vector(dot_filename)
    };
    //for (const auto s: text) { std::cerr << s << '\n'; }
    assert(!text.empty());
    const std::vector<std::string> expected_text{
      "graph G {",
      "0[label=\"Red\",comment=\"Not$$$SPACE$$$green\",width=1,height=2];",
      "1[label=\"Light$$$SPACE$$$red\",comment=\"Not$$$SPACE$$$dark\",width=3,height=4];",
      "2[label=\"Orange\",comment=\"Orangy\",width=5,height=6];",
      "0--1 [label=\"Oxygen\",comment=\"Air\",width=1,height=2];",
      "1--2 [label=\"Helium\",comment=\"From$$$SPACE$$$tube\",width=3,height=4];",
      "2--0 [label=\"Stable$$$SPACE$$$temperature\",comment=\"Here\",width=5,height=6];",
      "}"
    };
    assert(text == expected_text);
  }
  save_bundled_edges_and_vertices_graph_to_dot_demo();
  
}
