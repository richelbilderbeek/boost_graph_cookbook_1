#ifndef create_empty_undirected_named_edges_and_vertices_graph_H
#define create_empty_undirected_named_edges_and_vertices_graph_H

#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<boost::vertex_name_t,std::string>,
  boost::property<boost::edge_name_t,std::string>
>
create_empty_undirected_named_edges_and_vertices_graph() noexcept;

void create_empty_undirected_named_edges_and_vertices_graph_test() noexcept;

#endif // create_empty_undirected_named_edges_and_vertices_graph_H
