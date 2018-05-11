#ifndef LOAD_UNDIRECTED_NAMED_VERTICES_GRAPH_FROM_DOT_H
#define LOAD_UNDIRECTED_NAMED_VERTICES_GRAPH_FROM_DOT_H

#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ

#include "create_empty_undirected_named_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<
    boost::vertex_name_t,std::string
  >
>
load_undirected_named_vertices_graph_from_dot(
  const std::string& dot_filename
);

#else
#error(Do not include this file when BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ is defined)
#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ

#endif // LOAD_UNDIRECTED_NAMED_VERTICES_GRAPH_FROM_DOT_H
