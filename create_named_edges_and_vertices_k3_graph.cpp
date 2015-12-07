#include "create_named_edges_and_vertices_k3_graph.h"

#include "create_empty_named_edges_and_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<boost::vertex_name_t,std::string>,
  boost::property<boost::edge_name_t,std::string>
>
create_named_edges_and_vertices_k3_graph() noexcept
{
  auto g = create_empty_named_edges_and_vertices_graph();
  const auto vertex_descriptor_a = boost::add_vertex(g);
  const auto vertex_descriptor_b = boost::add_vertex(g);
  const auto vertex_descriptor_c = boost::add_vertex(g);
  const auto edge_insertion_result_ab
    = boost::add_edge(vertex_descriptor_a, vertex_descriptor_b, g);
  assert(edge_insertion_result_ab.second);
  const auto edge_insertion_result_bc
    = boost::add_edge(vertex_descriptor_b, vertex_descriptor_c, g);
  assert(edge_insertion_result_bc.second);
  const auto edge_insertion_result_ca
    = boost::add_edge(vertex_descriptor_c, vertex_descriptor_a, g);
  assert(edge_insertion_result_ca.second);

  //Add vertex names
  auto vertex_name_map = boost::get(boost::vertex_name,g);
  vertex_name_map[vertex_descriptor_a] = "top";
  vertex_name_map[vertex_descriptor_b] = "right";
  vertex_name_map[vertex_descriptor_c] = "left";

  //Add edge names
  auto edge_name_map = boost::get(boost::edge_name,g);
  edge_name_map[edge_insertion_result_ab.first] = "AB";
  edge_name_map[edge_insertion_result_bc.first] = "BC";
  edge_name_map[edge_insertion_result_ca.first] = "CA";

  return g;

}

