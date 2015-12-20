#ifndef CREATE_CUSTOM_VERTICES_MARKOV_CHAIN_H
#define CREATE_CUSTOM_VERTICES_MARKOV_CHAIN_H

#include <boost/graph/adjacency_list.hpp>
#include "install_vertex_custom_type.h"
#include "my_vertex.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::property<
    boost::vertex_custom_type_t,my_vertex
  >
>
create_custom_vertices_markov_chain() noexcept;

void create_custom_vertices_markov_chain_test() noexcept;

#endif // CREATE_CUSTOM_VERTICES_MARKOV_CHAIN_H
