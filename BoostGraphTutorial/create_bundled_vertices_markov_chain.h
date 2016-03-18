#ifndef CREATE_BUNDLED_VERTICES_MARKOV_CHAIN_H
#define CREATE_BUNDLED_VERTICES_MARKOV_CHAIN_H

#include <boost/graph/adjacency_list.hpp>
#include "my_bundled_vertex.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  my_bundled_vertex
>
create_bundled_vertices_markov_chain() noexcept;

#endif // CREATE_BUNDLED_VERTICES_MARKOV_CHAIN_H
