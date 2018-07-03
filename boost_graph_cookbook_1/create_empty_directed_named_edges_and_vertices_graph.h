#ifndef CREATE_EMPTY_DIRECTED_NAMED_EDGES_AND_VERTICES_GRAPH_H
#define CREATE_EMPTY_DIRECTED_NAMED_EDGES_AND_VERTICES_GRAPH_H

#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS,
  boost::property<boost::vertex_name_t, std::string>,
  boost::property<boost::edge_name_t, std::string>>
create_empty_directed_named_edges_and_vertices_graph() noexcept;

#endif // CREATE_EMPTY_DIRECTED_NAMED_EDGES_AND_VERTICES_GRAPH_H
