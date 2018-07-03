#ifndef LOAD_DIRECTED_TEXT_EDGES_AND_VERTICES_GRAPH_FROM_DOT_H
#define LOAD_DIRECTED_TEXT_EDGES_AND_VERTICES_GRAPH_FROM_DOT_H

#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ

#include "create_empty_directed_text_edges_and_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  std::string,
  std::string
>
load_directed_text_edges_and_vertices_graph_from_dot(
  const std::string& dot_filename
);

#else
#error(Do not include this file when BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ is defined)
#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ

#endif // LOAD_DIRECTED_TEXT_EDGES_AND_VERTICES_GRAPH_FROM_DOT_H
