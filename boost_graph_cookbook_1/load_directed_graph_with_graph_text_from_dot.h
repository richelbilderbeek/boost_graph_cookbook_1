#ifndef LOAD_DIRECTED_GRAPH_WITH_GRAPH_NAMES_FROM_DOT_H
#define LOAD_DIRECTED_GRAPH_WITH_GRAPH_NAMES_FROM_DOT_H

#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ

#include "create_empty_directed_graph_with_graph_text.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::no_property,
  boost::no_property,
  boost::property<
    boost::graph_text_t, std::string
  >
>
load_directed_graph_with_graph_text_from_dot(
  const std::string& dot_filetext
);

#else
#error(Do not include this file when BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ is defined)
#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ

#endif // LOAD_DIRECTED_GRAPH_WITH_GRAPH_NAMES_FROM_DOT_H
