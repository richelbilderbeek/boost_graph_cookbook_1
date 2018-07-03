#ifndef CREATE_NASTY_DIRECTED_TEXT_VERTICES_GRAPH_H
#define CREATE_NASTY_DIRECTED_TEXT_VERTICES_GRAPH_H

#include "create_empty_directed_text_vertices_graph.h"

boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, std::string>
create_nasty_directed_text_vertices_graph() noexcept;

#endif // CREATE_NASTY_DIRECTED_TEXT_VERTICES_GRAPH_H
