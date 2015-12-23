#ifndef SAVE_BUNDLED_EDGES_AND_VERTICES_GRAPH_TO_DOT_H
#define SAVE_BUNDLED_EDGES_AND_VERTICES_GRAPH_TO_DOT_H

#if __cplusplus >= 201402L //C++14
#include "save_bundled_edges_and_vertices_graph_to_dot_cpp14.impl"
#else
#include "save_bundled_edges_and_vertices_graph_to_dot_cpp11.impl"
#endif

void save_bundled_edges_and_vertices_graph_to_dot_test() noexcept;

#endif // SAVE_BUNDLED_EDGES_AND_VERTICES_GRAPH_TO_DOT_H
