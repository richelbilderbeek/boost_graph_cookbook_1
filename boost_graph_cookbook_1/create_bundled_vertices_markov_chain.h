#ifndef CREATE_BUNDLED_VERTICES_MARKOV_CHAIN_H
#define CREATE_BUNDLED_VERTICES_MARKOV_CHAIN_H

#include "my_bundled_vertex.h"
#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS,
  my_bundled_vertex>
create_bundled_vertices_markov_chain() noexcept;

#endif // CREATE_BUNDLED_VERTICES_MARKOV_CHAIN_H
