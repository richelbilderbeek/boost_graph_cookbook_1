#ifndef CREATE_MARKOV_CHAIN_GRAPH_H
#define CREATE_MARKOV_CHAIN_GRAPH_H

#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<>
create_markov_chain_graph() noexcept;

void create_markov_chain_graph_test() noexcept;


#endif // CREATE_MARKOV_CHAIN_GRAPH_H
