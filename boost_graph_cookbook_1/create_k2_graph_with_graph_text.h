#ifndef CREATE_K2_GRAPH_WITH_GRAPH_NAME_H
#define CREATE_K2_GRAPH_WITH_GRAPH_NAME_H

#include "create_empty_undirected_graph_with_graph_text.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::no_property,
  boost::no_property,
  boost::property<boost::graph_text_t,std::string>
>
create_k2_graph_with_graph_text() noexcept;

#endif // CREATE_K2_GRAPH_WITH_GRAPH_NAME_H
