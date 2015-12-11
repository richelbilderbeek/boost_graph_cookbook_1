#include "save_custom_edges_and_vertices_graph_to_dot.h"

#include <cassert>
#include <iostream>
#include <sstream>

#include "fileio.h"
#include "create_custom_edges_and_vertices_k3_graph.h"
#include "show_dot.h"
#include "convert_dot_to_svg.h"

void save_custom_edges_and_vertices_graph_to_dot_test() noexcept
{
  const ribi::FileIo f;
  //Show it does store the vertex names
  {
    const auto g = create_custom_edges_and_vertices_k3_graph();

    const std::string base_filename{"save_custom_edges_and_vertices_graph_to_dot_test_custom_edges_and_vertices_k3_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};

    save_custom_edges_and_vertices_graph_to_dot(g,dot_filename);
    assert(f.IsRegularFile(dot_filename));
    const std::vector<std::string> text{
      f.FileToVector(dot_filename)
    };
    assert(!text.empty());
    const std::vector<std::string> expected_text{
      "digraph G {",
      "}"
    };
    assert(text != expected_text);
    convert_dot_to_svg(dot_filename,svg_filename);
    f.CopyFile(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      ribi::fileio::CopyMode::allow_overwrite
    );
    f.CopyFile(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      ribi::fileio::CopyMode::allow_overwrite
    );
    //show_dot(filename);
  }
  //Show it does not store the edges' names
  {
    const auto g = create_custom_edges_and_vertices_k3_graph();
    const std::string base_filename{"save_custom_edges_and_vertices_graph_to_dot_test_custom_edges_and_vertices_k3_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};

    save_custom_edges_and_vertices_graph_to_dot(g,dot_filename);
    const std::vector<std::string> text{
      f.FileToVector(dot_filename)
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
    assert(text != expected_text);
    convert_dot_to_svg(dot_filename,svg_filename);
    f.CopyFile(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      ribi::fileio::CopyMode::allow_overwrite
    );
    f.CopyFile(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      ribi::fileio::CopyMode::allow_overwrite
    );
    //show_dot(filename);
  }
  std::cout << __func__ << ": OK" << '\n';
}
