#include "create_tutorial_chapters_graph.h"

#include "save_named_edges_and_vertices_graph_to_dot.h"

#include <cassert>
#include <iostream>
#include <sstream>

#include "fileio.h"
#include "convert_dot_to_svg.h"
#include "create_named_vertices_k2_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<boost::vertex_name_t,std::string>,
  boost::property<boost::edge_name_t,std::string>
>
create_tutorial_chapters_graph() noexcept
{
  using graph = boost::adjacency_list<
    boost::vecS,
    boost::vecS,
    boost::undirectedS,
    boost::property<
      boost::vertex_name_t,std::string
    >,
    boost::property<
      boost::edge_name_t,std::string
    >
  >;
  using vertex_descriptor
    = typename boost::graph_traits<graph>::vertex_descriptor;
  using edge_descriptor
    = typename boost::graph_traits<graph>::edge_descriptor;
  using edge_insertion_result
    = std::pair<edge_descriptor,bool>;
  using vertex_name_map_t
    = boost::property_map<graph,boost::vertex_name_t>::type;
  using edge_name_map_t
    = boost::property_map<graph,boost::edge_name_t>::type;

  graph g;
  const vertex_descriptor ceg = boost::add_vertex(g);
  const vertex_descriptor cenvg = boost::add_vertex(g);
  const vertex_descriptor ceneavg = boost::add_vertex(g);
  const vertex_descriptor cecvg = boost::add_vertex(g);
  const vertex_descriptor ceceavg = boost::add_vertex(g);

  const edge_insertion_result ceg_to_cenvg
    = boost::add_edge(ceg, cenvg, g);
  assert(ceg_to_cenvg.second);
  const edge_insertion_result cenvg_to_ceneavg
    = boost::add_edge(cenvg, ceneavg, g);
  assert(cenvg_to_ceneavg.second);
  const edge_insertion_result ceg_to_cecvg
    = boost::add_edge(ceg, cecvg, g);
  assert(ceg_to_cecvg.second);

  //Add vertex names
  vertex_name_map_t vertex_name_map{boost::get(boost::vertex_name,g)};
  vertex_name_map[ceg] = "create_empty_graph";
  vertex_name_map[cenvg] = "create_empty_named_vertices_graph";
  vertex_name_map[ceneavg] = "create_empty_named_edges_and_vertices_graph";
  vertex_name_map[cecvg] = "create_empty_custom_vertices_graph";
  vertex_name_map[ceceavg] = "create_empty_custom_edges_and_vertices_graph";

  //Add edge names
  edge_name_map_t edge_name_map{boost::get(boost::edge_name,g)};
  edge_name_map[ceg_to_cenvg.first] = "std::string vertex type";
  edge_name_map[cenvg_to_ceneavg.first] = "std::string edge type";
  edge_name_map[ceg_to_cecvg.first] = "custom vertex type";

  return g;
}



void create_tutorial_chapters_graph_test() noexcept
{
  {
    const auto g = create_tutorial_chapters_graph();
    const std::string base_filename{"create_tutorial_chapters_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_named_edges_and_vertices_graph_to_dot(g,dot_filename);
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
  std::cout << __func__ << ": OK" << '\n';
}
