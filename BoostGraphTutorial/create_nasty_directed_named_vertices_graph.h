#ifndef CREATE_NASTY_DIRECTED_NAMED_VERTICES_GRAPH_H
#define CREATE_NASTY_DIRECTED_NAMED_VERTICES_GRAPH_H

#include <boost/graph/adjacency_list.hpp>

///Create a nasty directed graph with named vertices
boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::property<boost::vertex_name_t,std::string>
>
create_nasty_directed_named_vertices_graph() noexcept;

void create_nasty_directed_named_vertices_graph_test() noexcept;



#endif // CREATE_NASTY_DIRECTED_NAMED_VERTICES_GRAPH_H
