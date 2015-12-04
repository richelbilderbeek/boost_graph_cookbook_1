#include "create_named_edges_and_vertices_k3_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<boost::vertex_name_t,std::string>,
  boost::property<boost::edge_name_t,std::string>
>
create_named_edges_and_vertices_k3_graph() noexcept
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
  const vertex_descriptor va = boost::add_vertex(g);
  const vertex_descriptor vb = boost::add_vertex(g);
  const vertex_descriptor vc = boost::add_vertex(g);
  const edge_insertion_result eab
    = boost::add_edge(va, vb, g);
  assert(eab.second);
  const edge_insertion_result ebc
    = boost::add_edge(vb, vc, g);
  assert(ebc.second);
  const edge_insertion_result eca
    = boost::add_edge(vc, va, g);
  assert(eca.second);

  //Add vertex names
  vertex_name_map_t vertex_name_map{boost::get(boost::vertex_name,g)};
  vertex_name_map[va] = "top";
  vertex_name_map[vb] = "right";
  vertex_name_map[vc] = "left";

  //Add edge names
  edge_name_map_t edge_name_map{boost::get(boost::edge_name,g)};
  edge_name_map[eab.first] = "AB";
  edge_name_map[ebc.first] = "BC";
  edge_name_map[eca.first] = "CA";

  return g;
}

