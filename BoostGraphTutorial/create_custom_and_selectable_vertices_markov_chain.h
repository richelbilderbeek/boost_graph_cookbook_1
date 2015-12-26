#ifndef CREATE_CUSTOM_AND_SELECTABLE_VERTICES_MARKOV_CHAIN_H
#define CREATE_CUSTOM_AND_SELECTABLE_VERTICES_MARKOV_CHAIN_H

#include "create_empty_directed_custom_and_selectable_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::property<
    boost::vertex_custom_type_t, my_custom_vertex,
    boost::property<
      boost::vertex_is_selected_t, bool
    >
  >
>
create_custom_and_selectable_vertices_markov_chain() noexcept;

void create_custom_and_selectable_vertices_markov_chain_test() noexcept;

#endif // CREATE_CUSTOM_AND_SELECTABLE_VERTICES_MARKOV_CHAIN_H
