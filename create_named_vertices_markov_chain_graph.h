#ifndef CREATE_NAMED_VERTICES_MARKOV_CHAIN_GRAPH_H
#define CREATE_NAMED_VERTICES_MARKOV_CHAIN_GRAPH_H

#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::property<boost::vertex_name_t,std::string>
>
create_named_vertices_markov_chain_graph() noexcept;

void create_named_vertices_markov_chain_graph_test() noexcept;

#endif // CREATE_NAMED_VERTICES_MARKOV_CHAIN_GRAPH_H
