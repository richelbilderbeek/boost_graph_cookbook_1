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

  //NODES 

  //Create graph
  const vertex_descriptor ceg = boost::add_vertex(g); //Create Empty Graph
  const vertex_descriptor cenvg = boost::add_vertex(g); //Create Empty Named Vertices Graph
  const vertex_descriptor ceneavg = boost::add_vertex(g); //Create Empty Named Edges And Vertices Graph
  const vertex_descriptor cecvg = boost::add_vertex(g); //Create Custom Named Vertices Graph
  const vertex_descriptor ceceavg = boost::add_vertex(g); //Create Custom Named Edges And Vertices Graph

  const vertex_descriptor ck2g = boost::add_vertex(g); //Create K2 Graph
  const vertex_descriptor cnvk2g = boost::add_vertex(g); //Create Named Vertices K2 Graph
  const vertex_descriptor cneavk2g = boost::add_vertex(g); //Create Named Edges And Vertices K3 Graph

  //Add vertex
  const vertex_descriptor av = boost::add_vertex(g);
  const vertex_descriptor anv = boost::add_vertex(g);
  const vertex_descriptor acv = boost::add_vertex(g);

  //Add edge
  const vertex_descriptor ae = boost::add_vertex(g);
  const vertex_descriptor ane = boost::add_vertex(g);
  const vertex_descriptor ace = boost::add_vertex(g);

  //EDGES

  //Create graph
  const edge_insertion_result ceg_to_cenvg = boost::add_edge(ceg, cenvg, g); assert(ceg_to_cenvg.second);
  const edge_insertion_result cenvg_to_ceneavg = boost::add_edge(cenvg, ceneavg, g); assert(cenvg_to_ceneavg.second);
  const edge_insertion_result ceg_to_cecvg = boost::add_edge(ceg, cecvg, g); assert(ceg_to_cecvg.second);
  const edge_insertion_result cecvg_to_ceceavg = boost::add_edge(cecvg, ceceavg, g); assert(ceg_to_cecvg.second);
  const edge_insertion_result ceg_to_ck2g = boost::add_edge(ceg, ck2g, g); assert(ceg_to_ck2g.second);
  const edge_insertion_result ck2g_to_cnvk2g = boost::add_edge(ck2g, cnvk2g, g); assert(ck2g_to_cnvk2g.second);
  const edge_insertion_result cnvk2g_to_cneavk2g = boost::add_edge(cnvk2g, cneavk2g, g); assert(cnvk2g_to_cneavk2g.second);

  //Add vertex
  const edge_insertion_result ceg_to_av = boost::add_edge(ceg, av, g); assert(ceg_to_av.second);
  const edge_insertion_result av_to_anv = boost::add_edge(av, anv, g); assert(av_to_anv.second);
  const edge_insertion_result av_to_acv = boost::add_edge(av, acv, g); assert(av_to_acv.second);

  //Add edge
  const edge_insertion_result ceg_to_ae = boost::add_edge(ceg, ae, g); assert(ceg_to_ae.second);
  const edge_insertion_result ae_to_ane = boost::add_edge(ae, ane, g); assert(ae_to_ane.second);
  const edge_insertion_result ae_to_ace = boost::add_edge(ae, ace, g); assert(ae_to_ace.second);

  //
  // NAMES OF VERTICES
  //
  vertex_name_map_t vertex_name_map{boost::get(boost::vertex_name,g)};

  //Create graph
  vertex_name_map[ceg] = "create_empty_graph";
  vertex_name_map[cenvg] = "create_empty_named_vertices_graph";
  vertex_name_map[ceneavg] = "create_empty_named_edges_and_vertices_graph";
  vertex_name_map[cecvg] = "create_empty_custom_vertices_graph";
  vertex_name_map[ceceavg] = "create_empty_custom_edges_and_vertices_graph";
  vertex_name_map[ck2g] = "create_k2_graph";
  vertex_name_map[cnvk2g] = "create_named_vertices_k2_graph";
  vertex_name_map[cneavk2g] = "create_named_edges_and_vertices_k2_graph";

  //Add vertex
  vertex_name_map[av] = "add_vertex";
  vertex_name_map[anv] = "add_named_vertex";
  vertex_name_map[acv] = "add_custom_vertex";

  //Add edge
  vertex_name_map[ae] = "add_edge";
  vertex_name_map[ane] = "add_named_edge";
  vertex_name_map[ace] = "add_custom_edge";


  //NAMES OF EDGES
  edge_name_map_t edge_name_map{boost::get(boost::edge_name,g)};
  edge_name_map[ceg_to_cenvg.first] = "std::string vertex type";
  edge_name_map[cenvg_to_ceneavg.first] = "std::string edge type";
  edge_name_map[ceg_to_cecvg.first] = "custom vertex type";
  edge_name_map[cecvg_to_ceceavg.first] = "custom edge type";


  edge_name_map[ceg_to_ck2g.first] = "add nodes and edge";
  edge_name_map[ck2g_to_cnvk2g.first] = "std::string vertex type";
  edge_name_map[cnvk2g_to_cneavk2g.first] = "std::string edge and vertex type";

  edge_name_map[ceg_to_av.first] = "add";
  edge_name_map[av_to_anv.first] = "std::string vertex type";
  edge_name_map[av_to_acv.first] = "custom vertex type";

  edge_name_map[ceg_to_ae.first] = "add";
  edge_name_map[ae_to_ane.first] = "std::string vertex type";
  edge_name_map[ae_to_ace.first] = "custom vertex type";


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
