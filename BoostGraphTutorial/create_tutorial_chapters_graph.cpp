#include "create_tutorial_chapters_graph.h"


#include <cassert>
#include <iostream>
#include <sstream>

#include "add_edge_between_named_vertices.h"
#include "add_named_vertex.h"
#include "convert_dot_to_svg.h"
#include "convert_svg_to_png.h"
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
  add_named_vertex("Graphs without properties", g);
  add_named_vertex("Graphs with named vertices", g);
  add_named_vertex("Graphs with named edges and vertices", g);
  add_named_vertex("Graphs with bundled vertices", g);
  add_named_vertex("Graphs with bundled edges and vertices", g);
  add_named_vertex("Graphs with custom vertices", g);
  add_named_vertex("Graphs with custom and selectable vertices", g);
  add_named_vertex("Graphs with custom edges and vertices", g);
  add_named_vertex("Graphs with a graph name", g);
  add_named_vertex("Graphs with custom graph properties", g);

  {
    const std::string s = "Graphs without properties";
    add_edge_between_named_vertices(s, "Graphs with named vertices", g);
    add_edge_between_named_vertices(s, "Graphs with bundled vertices", g);
    add_edge_between_named_vertices(s, "Graphs with custom vertices", g);
    add_edge_between_named_vertices(s, "Graphs with a graph name", g);
  }
  {
    const std::string s = "Graphs with named vertices";
    add_edge_between_named_vertices(s, "Graphs with named edges and vertices", g);
    add_edge_between_named_vertices(s, "Graphs with bundled vertices", g);
    add_edge_between_named_vertices(s, "Graphs with custom vertices", g);
    add_edge_between_named_vertices(s, "Graphs with a graph name", g);
  }
  {
    const std::string s = "Graphs with named edges and vertices";
    add_edge_between_named_vertices(s, "Graphs with bundled vertices", g);
    add_edge_between_named_vertices(s, "Graphs with custom vertices", g);
    add_edge_between_named_vertices(s, "Graphs with a graph name", g);
  }
  {
    const std::string s = "Graphs with bundled vertices";
    add_edge_between_named_vertices(s, "Graphs with named vertices", g);
    add_edge_between_named_vertices(s, "Graphs with bundled edges and vertices", g);
    add_edge_between_named_vertices(s, "Graphs with custom vertices", g);
    add_edge_between_named_vertices(s, "Graphs with a graph name", g);
  }
  {
    const std::string s = "Graphs with bundled edges and vertices";
    add_edge_between_named_vertices(s, "Graphs with named vertices", g);
    add_edge_between_named_vertices(s, "Graphs with custom vertices", g);
    add_edge_between_named_vertices(s, "Graphs with a graph name", g);
  }
  {
    const std::string s = "Graphs with custom vertices";
    add_edge_between_named_vertices(s, "Graphs with named vertices", g);
    add_edge_between_named_vertices(s, "Graphs with bundled vertices", g);
    add_edge_between_named_vertices(s, "Graphs with custom edges and vertices", g);
    add_edge_between_named_vertices(s, "Graphs with custom and selectable vertices", g);
    add_edge_between_named_vertices(s, "Graphs with a graph name", g);
  }
  {
    const std::string s = "Graphs with custom and selectable vertices";
    add_edge_between_named_vertices(s, "Graphs with named vertices", g);
    add_edge_between_named_vertices(s, "Graphs with bundled vertices", g);
    add_edge_between_named_vertices(s, "Graphs with custom edges and vertices", g);
    add_edge_between_named_vertices(s, "Graphs with a graph name", g);
  }
  {
    const std::string s = "Graphs with custom edges and vertices";
    add_edge_between_named_vertices(s, "Graphs with named vertices", g);
    add_edge_between_named_vertices(s, "Graphs with bundled vertices", g);
    add_edge_between_named_vertices(s, "Graphs with a graph name", g);
  }
  {
    const std::string s = "Graphs with a graph name";
    add_edge_between_named_vertices(s, "Graphs with named vertices", g);
    add_edge_between_named_vertices(s, "Graphs with bundled vertices", g);
    add_edge_between_named_vertices(s, "Graphs with custom vertices", g);
    add_edge_between_named_vertices(s, "Graphs with custom graph properties", g);
  }
  {
    const std::string s = "Graphs with custom graph properties";
    add_edge_between_named_vertices(s, "Graphs with named vertices", g);
    add_edge_between_named_vertices(s, "Graphs with bundled vertices", g);
    add_edge_between_named_vertices(s, "Graphs with custom vertices", g);
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
    const std::string png_filename{base_filename + ".png"};
    std::ofstream f(dot_filename);
    boost::write_graphviz(f,g);
    assert(is_valid_dot_file(dot_filename));
    convert_dot_to_svg(dot_filename,svg_filename);
    convert_svg_to_png(svg_filename,png_filename);
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
    copy_file(
      png_filename,
      "../BoostGraphTutorial/" + png_filename,
      copy_file_mode::allow_overwrite
    );
  }
  std::cout << __func__ << ": OK" << '\n';
}
