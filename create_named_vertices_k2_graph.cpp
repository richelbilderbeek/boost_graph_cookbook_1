#include "create_named_vertices_k2_graph.h"
#include "create_empty_named_vertices_graph.h"
boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<boost::vertex_name_t,std::string>
>
create_named_vertices_k2_graph() noexcept
{
  auto g = create_empty_named_vertices_graph();
  const auto vertex_descriptor_a = boost::add_vertex(g);
  const auto vertex_descriptor_b = boost::add_vertex(g);
  const auto edge_insertion_result
    = boost::add_edge(
    vertex_descriptor_a,
    vertex_descriptor_b,
    g
  );
  assert(edge_insertion_result.second);

  auto name_map = boost::get(boost::vertex_name,g);
  name_map[vertex_descriptor_a] = "from";
  name_map[vertex_descriptor_b] = "to";

  return g;
}


