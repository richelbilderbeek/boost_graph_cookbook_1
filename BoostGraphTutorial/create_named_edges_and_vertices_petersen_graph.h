#ifndef CREATE_NAMED_EDGES_AND_VERTICES_PETERSEN_GRAPH_H
#define CREATE_NAMED_EDGES_AND_VERTICES_PETERSEN_GRAPH_H

#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<boost::vertex_name_t, std::string>,
  boost::property<boost::edge_name_t, std::string>
>
create_named_edges_and_vertices_petersen_graph() noexcept;

#endif // CREATE_NAMED_EDGES_AND_VERTICES_PETERSEN_GRAPH_H
