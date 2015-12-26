#ifndef CREATE_MARKOV_CHAIN_WITH_GRAPH_NAME_H
#define CREATE_MARKOV_CHAIN_WITH_GRAPH_NAME_H

#include "create_empty_directed_graph_with_graph_name.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::no_property,
  boost::no_property,
  boost::property<boost::graph_name_t,std::string>
>
create_markov_chain_with_graph_name() noexcept;

void create_markov_chain_with_graph_name_test() noexcept;


#endif // CREATE_MARKOV_CHAIN_WITH_GRAPH_NAME_H
