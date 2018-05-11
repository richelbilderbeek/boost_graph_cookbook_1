#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
#include "save_bundled_edges_and_vertices_graph_to_dot.h"
#include "save_bundled_edges_and_vertices_graph_to_dot_demo.impl"

#include <boost/test/unit_test.hpp>
#include <sstream>

#include "copy_file.h"
#include "create_bundled_edges_and_vertices_k3_graph.h"
#include "show_dot.h"
#include "convert_dot_to_svg.h"
#include "file_to_vector.h"
#include "is_regular_file.h"

BOOST_AUTO_TEST_CASE(save_bundled_edges_and_vertices_graph_to_dot_thorough)
{
  //Show how it stores the create_bundled_edges_and_vertices_k3_graph
  {
    const auto g = create_bundled_edges_and_vertices_k3_graph();

    const std::string base_filename{"create_bundled_edges_and_vertices_k3_graph"};
    const std::string dot_filename{base_filename + ".dot"};

    save_bundled_edges_and_vertices_graph_to_dot(g,dot_filename);
    BOOST_CHECK(is_regular_file(dot_filename));
    const std::vector<std::string> text{
      file_to_vector(dot_filename)
    };
    //for (const auto s: text) { std::cerr << s << '\n'; }
    BOOST_CHECK(!text.empty());
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
    BOOST_CHECK(text == expected_text);
    std::remove(dot_filename.c_str());
  }
}

#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
