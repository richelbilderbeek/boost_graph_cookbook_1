#ifndef LOAD_DIRECTED_GRAPH_WITH_GRAPH_NAMES_FROM_DOT_H
#define LOAD_DIRECTED_GRAPH_WITH_GRAPH_NAMES_FROM_DOT_H

#ifndef BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ

#include "create_empty_directed_graph_with_graph_name.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::no_property,
  boost::no_property,
  boost::property<
    boost::graph_name_t, std::string
  >
>
load_directed_graph_with_graph_name_from_dot(
  const std::string& dot_filename
);

#else
#error(Do not include this file when BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ is defined)
#endif // BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ

#endif // LOAD_DIRECTED_GRAPH_WITH_GRAPH_NAMES_FROM_DOT_H
