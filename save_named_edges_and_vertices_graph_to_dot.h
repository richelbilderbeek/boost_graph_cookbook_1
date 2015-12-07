#ifndef SAVE_NAMED_EDGES_AND_VERTICES_GRAPH_TO_DOT
#define SAVE_NAMED_EDGES_AND_VERTICES_GRAPH_TO_DOT

#if __cplusplus >= 201402L //C++17
#include "save_named_edges_and_vertices_graph_to_dot_cpp17.impl"
#else
#include "save_named_edges_and_vertices_graph_to_dot_cpp14.impl"
#endif

void save_named_edges_and_vertices_graph_to_dot_test() noexcept;

#endif // SAVE_NAMED_EDGES_AND_VERTICES_GRAPH_TO_DOT

