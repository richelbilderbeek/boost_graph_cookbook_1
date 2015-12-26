#ifndef LOAD_UNDIRECTED_GRAPH_WITH_GRAPH_NAMES_FROM_DOT_H
#define LOAD_UNDIRECTED_GRAPH_WITH_GRAPH_NAMES_FROM_DOT_H

#include "create_empty_undirected_graph_with_graph_name.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::no_property,
  boost::no_property,
  boost::property<
    boost::graph_name_t, std::string
  >
>
load_undirected_graph_with_graph_name_from_dot(
  const std::string& dot_filename
);

void load_undirected_graph_with_graph_name_from_dot_test() noexcept;


#endif // LOAD_UNDIRECTED_GRAPH_WITH_GRAPH_NAMES_FROM_DOT_H
