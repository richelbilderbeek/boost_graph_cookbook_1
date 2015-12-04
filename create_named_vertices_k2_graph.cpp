#include "create_named_vertices_k2_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<boost::vertex_name_t,std::string>
>
create_named_vertices_k2_graph() noexcept
{
  using graph = boost::adjacency_list<
    boost::vecS,
    boost::vecS,
    boost::undirectedS,
    boost::property<
      boost::vertex_name_t,std::string
    >
  >;
  using vertex_descriptor
    = typename boost::graph_traits<graph>::vertex_descriptor;
  using edge_descriptor
    = typename boost::graph_traits<graph>::edge_descriptor;
  using edge_insertion_result
    = std::pair<edge_descriptor,bool>;
  using name_map_t
    = boost::property_map<graph,boost::vertex_name_t>::type;

  graph g;
  const vertex_descriptor va = boost::add_vertex(g);
  const vertex_descriptor vb = boost::add_vertex(g);
  const edge_insertion_result ea
    = boost::add_edge(va, vb, g);
  assert(ea.second);

  //Add names
  name_map_t name_map{boost::get(boost::vertex_name,g)};
  name_map[va] = "from";
  name_map[vb] = "to";

  return g;
}


