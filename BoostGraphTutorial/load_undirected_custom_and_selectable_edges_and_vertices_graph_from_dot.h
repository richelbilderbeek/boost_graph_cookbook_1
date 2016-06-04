#ifndef LOAD_UNDIRECTED_CUSTOM_AND_SELECTABLE_EDGES_AND_VERTICES_GRAPH_FROM_DOT_H
#define LOAD_UNDIRECTED_CUSTOM_AND_SELECTABLE_EDGES_AND_VERTICES_GRAPH_FROM_DOT_H

#include "load_undirected_custom_and_selectable_edges_and_vertices_graph_from_dot.impl"

/*
boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<
    boost::vertex_custom_type_t, my_custom_vertex,
    boost::property<
      boost::vertex_is_selected_t, bool
    >
  >,
  boost::property<
    boost::edge_custom_type_t, my_custom_edge,
    boost::property<
      boost::edge_is_selected_t, bool
    >
  >
>
load_undirected_custom_and_selectable_edges_and_vertices_graph_from_dot(
  const std::string& dot_filename
);
*/

#endif // LOAD_UNDIRECTED_CUSTOM_AND_SELECTABLE_EDGES_AND_VERTICES_GRAPH_FROM_DOT_H
