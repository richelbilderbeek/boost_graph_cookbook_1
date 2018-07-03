#ifndef CREATE_TEXT_VERTICES_MARKOV_CHAIN_H
#define CREATE_TEXT_VERTICES_MARKOV_CHAIN_H

#include "create_empty_directed_text_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  std::string
>
create_text_vertices_markov_chain() noexcept;

#endif // CREATE_TEXT_VERTICES_MARKOV_CHAIN_H
