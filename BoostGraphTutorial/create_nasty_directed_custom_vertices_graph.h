#ifndef CREATE_NASTY_DIRECTED_CUSTOM_VERTICES_GRAPH_H
#define CREATE_NASTY_DIRECTED_CUSTOM_VERTICES_GRAPH_H

#include "create_empty_directed_custom_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::property<
    boost::vertex_custom_type_t, my_custom_vertex
  >
>
create_nasty_directed_custom_vertices_graph() noexcept;

void create_nasty_directed_custom_vertices_graph_test() noexcept;

#endif // CREATE_NASTY_DIRECTED_CUSTOM_VERTICES_GRAPH_H
