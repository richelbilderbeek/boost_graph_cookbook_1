#include "save_named_vertices_graph_to_dot.h"

#include "create_named_vertices_k2_graph.h"
#include "create_named_vertices_markov_chain_graph.h"
#include "save_named_vertices_graph_to_dot.h"

void save_named_vertices_graph_to_dot_demo() noexcept
{
  const auto g = create_named_vertices_k2_graph();
  save_named_vertices_graph_to_dot(g, "create_named_vertices_k2_graph.dot");

  const auto h = create_named_vertices_markov_chain_graph();
  save_named_vertices_graph_to_dot(h, "create_named_vertices_markov_chain_graph.dot");
}

#include <cassert>
#include <iostream>
#include <sstream>

#include "fileio.h"
#include "create_k2_graph.h"
#include "create_named_vertices_k2_graph.h"
#include "create_named_vertices_markov_chain_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"
#include "create_router_network_graph.h"
#include "show_dot.h"
#include "convert_dot_to_svg.h"
#include "set_vertex_names.h"

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
    ribi::FileIo().CopyFile(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      ribi::fileio::CopyMode::allow_overwrite
    );
    ribi::FileIo().CopyFile(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      ribi::fileio::CopyMode::allow_overwrite
    );
  }
  //Create figure of named Markov chain graph
  {
    const auto g = create_named_vertices_markov_chain_graph();
    const std::string base_filename{"create_named_vertices_markov_chain_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_named_vertices_graph_to_dot(g,dot_filename);
    convert_dot_to_svg(dot_filename,svg_filename);
    ribi::FileIo().CopyFile(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      ribi::fileio::CopyMode::allow_overwrite
    );
    ribi::FileIo().CopyFile(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      ribi::fileio::CopyMode::allow_overwrite
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
      ribi::FileIo().FileToVector(dot_filename)
    };
    assert(!text.empty());
    const std::vector<std::string> expected_text{
      "graph G {",
      "0[label=from];",
      "1[label=to];",
      "0--1 ;",
      "}"
    };
    assert(text == expected_text);
    convert_dot_to_svg(dot_filename,svg_filename);
    ribi::FileIo().CopyFile(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      ribi::fileio::CopyMode::allow_overwrite
    );
    ribi::FileIo().CopyFile(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      ribi::fileio::CopyMode::allow_overwrite
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
      ribi::FileIo().FileToVector(dot_filename)
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
    ribi::FileIo().CopyFile(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      ribi::fileio::CopyMode::allow_overwrite
    );
    ribi::FileIo().CopyFile(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      ribi::fileio::CopyMode::allow_overwrite
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
      ribi::FileIo().FileToVector(dot_filename)
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
    ribi::FileIo().CopyFile(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      ribi::fileio::CopyMode::allow_overwrite
    );
    ribi::FileIo().CopyFile(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      ribi::fileio::CopyMode::allow_overwrite
    );
  }
  save_named_vertices_graph_to_dot_demo();
  std::cout << __func__ << ": OK" << '\n';
}
