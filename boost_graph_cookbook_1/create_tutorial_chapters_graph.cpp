#include "create_tutorial_chapters_graph.h"

#include <sstream>

#include "add_edge_between_named_vertices.h"
#include "add_named_vertex.h"
#include "convert_dot_to_svg.h"
#include "convert_svg_to_png.h"
#include "copy_file.h"
#include "create_empty_directed_named_vertices_graph.h"
#include "is_valid_dot_file.h"
#include "save_graph_to_dot.h"
#include "save_named_vertices_graph_to_dot.h"

boost::adjacency_list< //! OCLINT Sure it is too long, but this is just a fun
                       //! function
  boost::vecS, boost::vecS, boost::directedS,
  boost::property<boost::vertex_name_t, std::string>>
create_tutorial_chapters_graph()
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
  add_named_vertex("Graphs with custom and selectable edges and vertices", g);
  add_named_vertex("Graphs with a graph name", g);

  {
    const std::string s = "Graphs without properties";
    add_edge_between_named_vertices(
      s, std::string("Graphs with named vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with bundled vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with custom vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with a graph name"), g);
  }
  {
    const std::string s = "Graphs with named vertices";
    add_edge_between_named_vertices(
      s, std::string("Graphs with named edges and vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with bundled vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with custom vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with a graph name"), g);
  }
  {
    const std::string s = "Graphs with named edges and vertices";
    add_edge_between_named_vertices(
      s, std::string("Graphs with bundled vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with custom vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with a graph name"), g);
  }
  {
    const std::string s = "Graphs with bundled vertices";
    add_edge_between_named_vertices(
      s, std::string("Graphs with named vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with bundled edges and vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with custom vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with a graph name"), g);
  }
  {
    const std::string s = "Graphs with bundled edges and vertices";
    add_edge_between_named_vertices(
      s, std::string("Graphs with named vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with custom vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with a graph name"), g);
  }
  {
    const std::string s = "Graphs with custom vertices";
    add_edge_between_named_vertices(
      s, std::string("Graphs with named vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with bundled vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with custom edges and vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with custom and selectable vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with a graph name"), g);
  }
  {
    const std::string s = "Graphs with custom and selectable vertices";
    add_edge_between_named_vertices(
      s, std::string("Graphs with named vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with bundled vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with custom edges and vertices"), g);
    add_edge_between_named_vertices(s,
      std::string("Graphs with custom and selectable edges and vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with a graph name"), g);
  }
  {
    const std::string s = "Graphs with custom edges and vertices";
    add_edge_between_named_vertices(
      s, std::string("Graphs with named vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with bundled vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with custom and selectable vertices"), g);
    add_edge_between_named_vertices(s,
      std::string("Graphs with custom and selectable edges and vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with a graph name"), g);
  }

  {
    const std::string s
      = "Graphs with custom and selectable edges and vertices";
    add_edge_between_named_vertices(
      s, std::string("Graphs with named vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with bundled vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with a graph name"), g);
  }

  {
    const std::string s = "Graphs with a graph name";
    add_edge_between_named_vertices(
      s, std::string("Graphs with named vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with bundled vertices"), g);
    add_edge_between_named_vertices(
      s, std::string("Graphs with custom vertices"), g);
  }
  return g;
}
