#ifndef CREATE_NAMED_EDGES_AND_VERTICES_MARKOV_CHAIN_GRAPH_H
#define CREATE_NAMED_EDGES_AND_VERTICES_MARKOV_CHAIN_GRAPH_H

#include "create_empty_directed_named_edges_and_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::property<boost::vertex_name_t,std::string>,
  boost::property<boost::edge_name_t,std::string>
>
create_named_edges_and_vertices_markov_chain() noexcept;

void create_named_edges_and_vertices_markov_chain_test() noexcept;

#endif // CREATE_NAMED_EDGES_AND_VERTICES_MARKOV_CHAIN_GRAPH_H
