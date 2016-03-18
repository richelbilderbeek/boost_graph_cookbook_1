#ifndef CREATE_NAMED_VERTICES_MARKOV_CHAIN_H
#define CREATE_NAMED_VERTICES_MARKOV_CHAIN_H

#include "create_empty_directed_named_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::property<boost::vertex_name_t,std::string>
>
create_named_vertices_markov_chain() noexcept;

#endif // CREATE_NAMED_VERTICES_MARKOV_CHAIN_H
