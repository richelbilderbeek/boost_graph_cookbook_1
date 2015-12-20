#include "save_named_vertices_graph_to_dot.h"

#if __cplusplus >= 201402L //C++14
#include "save_named_vertices_graph_to_dot_using_lambda_cpp14.impl"
#else
#include "save_named_vertices_graph_to_dot_using_lambda_cpp11.impl"
#endif

#include "create_named_vertices_k2_graph.h"
#include "create_named_vertices_markov_chain.h"
#include "save_named_vertices_graph_to_dot.h"


void save_named_vertices_graph_to_dot_demo() noexcept
{
  const auto g = create_named_vertices_k2_graph();
  save_named_vertices_graph_to_dot(g, "create_named_vertices_k2_graph.dot");

  const auto h = create_named_vertices_markov_chain();
  save_named_vertices_graph_to_dot(h, "create_named_vertices_markov_chain.dot");
}

#include <cassert>
#include <iostream>
#include <sstream>

#include "copy_file.h"
#include "create_k2_graph.h"
#include "create_named_vertices_k2_graph.h"
#include "create_named_vertices_markov_chain.h"
#include "create_named_edges_and_vertices_k3_graph.h"
#include "show_dot.h"
#include "convert_dot_to_svg.h"
#include "set_vertex_names.h"
#include "helper.h"


void save_named_vertices_graph_to_dot_test() noexcept
{
  //Create figure of named K2 graph
  {
    const auto g = create_named_vertices_k2_graph();
    const std::string base_filename{"create_named_vertices_k2_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_named_vertices_graph_to_dot(g,dot_filename);
    convert_dot_to_svg(dot_filename,svg_filename);
    copy_file(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
  }
  //Create figure of named Markov chain graph
  {
    const auto g = create_named_vertices_markov_chain();
    const std::string base_filename{"create_named_vertices_markov_chain"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_named_vertices_graph_to_dot(g,dot_filename);
    convert_dot_to_svg(dot_filename,svg_filename);
    copy_file(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
  }
  //Show it does store the vertex names
  {
    const auto g = create_named_vertices_k2_graph();

    const std::string base_filename{"save_named_vertices_graph_to_dot_test_named_vertices_k2_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};

    save_named_vertices_graph_to_dot(g,dot_filename);
    const std::vector<std::string> text{
      helper().file_to_vector(dot_filename)
    };
    assert(!text.empty());
    const std::vector<std::string> expected_text{
      "graph G {",
      "0[label=A];",
      "1[label=B];",
      "0--1 ;",
      "}"
    };
    assert(text == expected_text);
    convert_dot_to_svg(dot_filename,svg_filename);
    copy_file(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
    //show_dot(filename);
  }
  //Show it does not store the edges' names
  {
    const auto g = create_named_edges_and_vertices_k3_graph();
    const std::string base_filename{"save_named_vertices_graph_to_dot_test_named_edges_and_vertices_k3_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};

    save_named_vertices_graph_to_dot(g,dot_filename);
    const std::vector<std::string> text{
      helper().file_to_vector(dot_filename)
    };
    assert(!text.empty());
    const std::vector<std::string> expected_text{
      "graph G {",
      "0[label=top];",
      "1[label=right];",
      "2[label=left];",
      "0--1 ;",
      "1--2 ;",
      "2--0 ;",
      "}"
    };
    assert(text == expected_text);
    convert_dot_to_svg(dot_filename,svg_filename);
    copy_file(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
    //show_dot(filename);
  }
  //Will it break if the vertices have named with spaces
  {
    auto g = create_named_vertices_k2_graph();
    const std::string word_1{"Hello world"};
    const std::string word_2{"Hasta la vista"};
    const std::vector<std::string> v{word_1, word_2};
    set_vertex_names(g,v);

    const std::string base_filename{"save_named_vertices_graph_to_dot_test_named_vertices_k2_graph_with_space"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};

    save_named_vertices_graph_to_dot(g,dot_filename);
    const std::vector<std::string> text{
      helper().file_to_vector(dot_filename)
    };
    assert(!text.empty());
    const std::vector<std::string> expected_text{
      "graph G {",
      "0[label=\"" + word_1 + "\"];",
      "1[label=\"" + word_2 + "\"];",
      "0--1 ;",
      "}"
    };
    assert(text == expected_text);
    convert_dot_to_svg(dot_filename,svg_filename);
    copy_file(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
  }
  //Compare ways of save_named_vertices_graph_to_dot to be equivalent:
  // - use boost::make_label_writes
  // - use lambda in C++11
  // - use lambda in C++14
  #if __cplusplus >= 201402L //C++14
  {
    const auto g = create_named_vertices_k2_graph();
    const auto h = create_named_vertices_markov_chain();
    save_named_vertices_graph_to_dot(g,"g1.dot");
    save_named_vertices_graph_to_dot_using_lambda_cpp14(g,"g2.dot");
    save_named_vertices_graph_to_dot(h,"h1.dot");
    save_named_vertices_graph_to_dot_using_lambda_cpp14(h,"h2.dot");
    assert(helper().file_to_vector("g1.dot") == helper().file_to_vector("g2.dot"));
    assert(helper().file_to_vector("h1.dot") == helper().file_to_vector("h2.dot"));
    assert(helper().file_to_vector("g1.dot") != helper().file_to_vector("h2.dot"));
  }
  #else
  {
    const auto g = create_named_vertices_k2_graph();
    const auto h = create_named_vertices_markov_chain();
    save_named_vertices_graph_to_dot(g,"g1.dot");
    save_named_vertices_graph_to_dot_using_lambda_cpp11(g,"g2.dot");
    save_named_vertices_graph_to_dot(h,"h1.dot");
    save_named_vertices_graph_to_dot_using_lambda_cpp11(h,"h2.dot");
    assert(helper().file_to_vector("g1.dot") == helper().file_to_vector("g2.dot"));
    assert(helper().file_to_vector("h1.dot") == helper().file_to_vector("h2.dot"));
    assert(helper().file_to_vector("g1.dot") != helper().file_to_vector("h2.dot"));
  }
  #endif
  save_named_vertices_graph_to_dot_demo();
  std::cout << __func__ << ": OK" << '\n';
}
