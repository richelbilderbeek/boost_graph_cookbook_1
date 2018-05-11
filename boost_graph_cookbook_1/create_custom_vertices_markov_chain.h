#ifndef CREATE_CUSTOM_VERTICES_MARKOV_CHAIN_H
#define CREATE_CUSTOM_VERTICES_MARKOV_CHAIN_H

#include "create_empty_directed_custom_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::property<
    boost::vertex_custom_type_t, my_custom_vertex
  >
>
create_custom_vertices_markov_chain() noexcept;

#endif // CREATE_CUSTOM_VERTICES_MARKOV_CHAIN_H
