#ifndef CREATE_TEXT_EDGES_AND_VERTICES_K2_GRAPH_H
#define CREATE_TEXT_EDGES_AND_VERTICES_K2_GRAPH_H

#include "create_empty_undirected_text_edges_and_vertices_graph.h"

boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, std::string,
  std::string>
create_text_edges_and_vertices_k2_graph();

#endif // CREATE_TEXT_EDGES_AND_VERTICES_K2_GRAPH_H
