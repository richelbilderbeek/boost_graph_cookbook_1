#ifndef LOAD_DIRECTED_GRAPH_FROM_DOT_H
#define LOAD_DIRECTED_GRAPH_FROM_DOT_H

#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ

#include "create_empty_directed_graph.h"

boost::adjacency_list<> load_directed_graph_from_dot(
  const std::string& dot_filename);

#else
#error(Do not include this file when BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ is defined)
#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ

#endif // LOAD_DIRECTED_GRAPH_FROM_DOT_H
