#ifndef CREATE_EMPTY_UNDIRECTED_NAMED_EDGES_AND_VERTICES_GRAPH_H
#define CREATE_EMPTY_UNDIRECTED_NAMED_EDGES_AND_VERTICES_GRAPH_H

#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<boost::vertex_name_t,std::string>,
  boost::property<boost::edge_name_t,std::string>
>
create_empty_undirected_text_edges_and_vertices_graph() noexcept;

#endif // CREATE_EMPTY_UNDIRECTED_NAMED_EDGES_AND_VERTICES_GRAPH_H
