#ifndef CREATE_NAMED_EDGES_AND_VERTICES_K2_GRAPH_H
#define CREATE_NAMED_EDGES_AND_VERTICES_K2_GRAPH_H

#include "create_empty_undirected_text_edges_and_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<boost::vertex_name_t,std::string>,
  boost::property<boost::edge_name_t,std::string>
>
create_text_edges_and_vertices_k2_graph();

#endif // CREATE_NAMED_EDGES_AND_VERTICES_K2_GRAPH_H

