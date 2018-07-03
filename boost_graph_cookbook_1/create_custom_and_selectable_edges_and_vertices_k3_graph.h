#ifndef CREATE_CUSTOM_AND_SELECTABLE_EDGES_AND_VERTICES_K3_GRAPH_H
#define CREATE_CUSTOM_AND_SELECTABLE_EDGES_AND_VERTICES_K3_GRAPH_H

#include "create_empty_undirected_custom_and_selectable_edges_and_vertices_graph.h"

boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
  boost::property<boost::vertex_custom_type_t, my_custom_vertex,
    boost::property<boost::vertex_is_selected_t, bool>>,
  boost::property<boost::edge_custom_type_t, my_custom_edge,
    boost::property<boost::edge_is_selected_t, bool>>>
create_custom_and_selectable_edges_and_vertices_k3_graph();

#endif // CREATE_CUSTOM_AND_SELECTABLE_EDGES_AND_VERTICES_K3_GRAPH_H
