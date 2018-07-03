#ifndef CREATE_TEXT_VERTICES_K2_GRAPH_H
#define CREATE_TEXT_VERTICES_K2_GRAPH_H

#include "create_empty_undirected_text_vertices_graph.h"

boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, std::string>
create_text_vertices_k2_graph() noexcept;

#endif // CREATE_TEXT_VERTICES_K2_GRAPH_H
