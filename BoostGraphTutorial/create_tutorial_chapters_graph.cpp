#include "create_tutorial_chapters_graph.h"


#include <cassert>
#include <iostream>
#include <sstream>

#include "add_edge_between_named_vertices.h"
#include "add_named_vertex.h"
#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_empty_directed_named_vertices_graph.h"
#include "is_valid_dot_file.h"
#include "save_named_vertices_graph_to_dot.h"
#include "save_graph_to_dot.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::property<boost::vertex_name_t,std::string>
>
create_tutorial_chapters_graph() noexcept
{
  auto g = create_empty_directed_named_vertices_graph();
  add_named_vertex("Building graphs without properties", g);
  add_named_vertex("Working on graphs without properties", g);
  add_named_vertex("Building graphs with named vertices", g);
  add_named_vertex("Working on graphs with named vertices", g);
  add_named_vertex("Building graphs with named edges and vertices", g);
  add_named_vertex("Working on graphs with named edges and vertices", g);
  add_named_vertex("Building graphs with bundled vertices", g);
  add_named_vertex("Working on graphs with bundled vertices", g);
  add_named_vertex("Building graphs with bundled edges and vertices", g);
  add_named_vertex("Working on graphs with bundled edges and vertices", g);
  add_named_vertex("Building graphs with custom vertices", g);
  add_named_vertex("Working on graphs with custom vertices", g);
  add_named_vertex("Building graphs with custom edges and vertices", g);
  add_named_vertex("Working on graphs with custom edges and vertices", g);
  add_named_vertex("Building graphs with a graph name", g);
  add_named_vertex("Working on graphs with a graph name", g);
  add_named_vertex("Building graphs with custom graph properties", g);
  add_named_vertex("Working on graphs with custom graph properties", g);

  {
    const std::string s = "Building graphs without properties";
    add_edge_between_named_vertices(s, "Working on graphs without properties", g);
    add_edge_between_named_vertices(s, "Building graphs with named vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with custom vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with a graph name", g);
  }
  {
    const std::string s = "Working on graphs without properties";
    add_edge_between_named_vertices(s, "Building graphs with named vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with custom vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with a graph name", g);
    add_edge_between_named_vertices(s, "Working on graphs with named vertices", g);
    add_edge_between_named_vertices(s, "Working on graphs with custom vertices", g);
    add_edge_between_named_vertices(s, "Working on graphs with a graph name", g);
  }
  {
    const std::string s = "Building graphs with named vertices";
    add_edge_between_named_vertices(s, "Working on graphs with named vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with named edges and vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with custom vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with a graph name", g);
  }
  {
    const std::string s = "Working on graphs with named vertices";
    add_edge_between_named_vertices(s, "Building graphs with named edges and vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with bundled vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with custom vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with a graph name", g);
    add_edge_between_named_vertices(s, "Working on graphs with named edges and vertices", g);
    add_edge_between_named_vertices(s, "Working on graphs with custom vertices", g);
    add_edge_between_named_vertices(s, "Working on graphs with a graph name", g);
  }
  {
    const std::string s = "Building graphs with named edges and vertices";
    add_edge_between_named_vertices(s, "Working on graphs with named edges and vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with custom vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with a graph name", g);
  }
  {
    const std::string s = "Working on graphs with named edges and vertices";
    add_edge_between_named_vertices(s, "Building graphs with custom vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with a graph name", g);
    add_edge_between_named_vertices(s, "Working on graphs with custom vertices", g);
    add_edge_between_named_vertices(s, "Working on graphs with a graph name", g);
  }
  {
    const std::string s = "Building graphs with bundled vertices";
    add_edge_between_named_vertices(s, "Working on graphs with bundled vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with named vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with custom vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with bundled edges and vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with a graph name", g);
  }

  {
    const std::string s = "Working on graphs with bundled vertices";
    add_edge_between_named_vertices(s, "Building graphs with named vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with bundled edges and vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with custom vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with a graph name", g);
  }

  {
    const std::string s = "Building graphs with bundled edges and vertices";
    add_edge_between_named_vertices(s, "Working on graphs with bundled edges and vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with named vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with custom vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with a graph name", g);
  }

  {
    const std::string s = "Working on graphs with bundled edges and vertices";
    add_edge_between_named_vertices(s, "Building graphs with named vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with bundled edges and vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with custom vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with a graph name", g);
  }

  {
    const std::string s = "Building graphs with custom vertices";
    add_edge_between_named_vertices(s, "Working on graphs with custom vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with named vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with bundled vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with custom edges and vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with a graph name", g);
  }
  {
    const std::string s = "Working on graphs with custom vertices";
    add_edge_between_named_vertices(s, "Building graphs with custom edges and vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with a graph name", g);
    add_edge_between_named_vertices(s, "Working on graphs with custom edges and vertices", g);
    add_edge_between_named_vertices(s, "Working on graphs with a graph name", g);
  }
  {
    const std::string s = "Building graphs with custom edges and vertices";
    add_edge_between_named_vertices(s, "Working on graphs with custom edges and vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with named vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with bundled vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with a graph name", g);
  }
  {
    const std::string s = "Working on graphs with custom edges and vertices";
    add_edge_between_named_vertices(s, "Building graphs with a graph name", g);
  }
  {
    const std::string s = "Building graphs with a graph name";
    add_edge_between_named_vertices(s, "Working on graphs with a graph name", g);
    add_edge_between_named_vertices(s, "Building graphs with named vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with bundled vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with custom vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with custom graph properties", g);
  }
  {
    const std::string s = "Working on graphs with a graph name";
    add_edge_between_named_vertices(s, "Building graphs with custom graph properties", g);
    add_edge_between_named_vertices(s, "Building graphs with named vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with bundled vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with custom vertices", g);
  }
  {
    const std::string s = "Building graphs with custom graph properties";
    add_edge_between_named_vertices(s, "Working on graphs with custom graph properties", g);
  }
  {
    const std::string s = "Working on graphs with custom graph properties";
    add_edge_between_named_vertices(s, "Building graphs with named vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with bundled vertices", g);
    add_edge_between_named_vertices(s, "Building graphs with custom vertices", g);
  }
  return g;
}



void create_tutorial_chapters_graph_test() noexcept
{
  //Create the 'relation between chapters' figure
  {
    const auto g = create_tutorial_chapters_graph();
    const std::string base_filename{"create_tutorial_chapters_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_named_vertices_graph_to_dot(g,dot_filename);
    assert(is_valid_dot_file(dot_filename));
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
  //Create the title figure
  {
    const auto g = create_tutorial_chapters_graph();
    const std::string base_filename{"title_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_graph_to_dot(g,dot_filename);
    assert(is_valid_dot_file(dot_filename));
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
  std::cout << __func__ << ": OK" << '\n';
}
