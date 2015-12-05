#ifndef CREATE_NAMED_VERTICES_K2_GRAPH_H
#define CREATE_NAMED_VERTICES_K2_GRAPH_H

#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<boost::vertex_name_t,std::string>
>
create_named_vertices_k2_graph() noexcept;

void create_named_vertices_k2_graph_test() noexcept;

#endif // CREATE_NAMED_VERTICES_K2_GRAPH_H
