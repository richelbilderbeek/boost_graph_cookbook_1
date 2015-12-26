#ifndef LOAD_UNDIRECTED_CUSTOM_AND_SELECTABLE_VERTICES_GRAPH_FROM_DOT_H
#define LOAD_UNDIRECTED_CUSTOM_AND_SELECTABLE_VERTICES_GRAPH_FROM_DOT_H

#include "create_empty_undirected_custom_and_selectable_vertices_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<
    boost::vertex_custom_type_t, my_custom_vertex,
    boost::property<
      boost::vertex_is_selected_t, bool
    >
  >
>
load_undirected_custom_and_selectable_vertices_graph_from_dot(
  const std::string& dot_filename
);

void load_undirected_custom_and_selectable_vertices_graph_from_dot_test() noexcept;


#endif // LOAD_UNDIRECTED_CUSTOM_AND_SELECTABLE_VERTICES_GRAPH_FROM_DOT_H
