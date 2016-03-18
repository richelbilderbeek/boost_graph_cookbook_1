#ifndef CREATE_K2_GRAPH_WITH_GRAPH_NAME_H
#define CREATE_K2_GRAPH_WITH_GRAPH_NAME_H

#include "create_empty_undirected_graph_with_graph_name.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::no_property,
  boost::no_property,
  boost::property<boost::graph_name_t,std::string>
>
create_k2_graph_with_graph_name() noexcept;

#endif // CREATE_K2_GRAPH_WITH_GRAPH_NAME_H
