#ifndef CREATE_CUSTOM_EDGES_AND_VERTICES_PATH_GRAPH_H
#define CREATE_CUSTOM_EDGES_AND_VERTICES_PATH_GRAPH_H

#include <vector>
#include <boost/graph/adjacency_list.hpp>
#include "install_edge_custom_type.h"
#include "install_vertex_custom_type.h"
#include "my_custom_edge.h"
#include "my_custom_vertex.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<
    boost::vertex_custom_type_t, my_custom_vertex
  >,
  boost::property<
    boost::edge_custom_type_t, my_custom_edge
  >
>
create_custom_edges_and_vertices_path_graph(
  const std::vector<my_custom_edge>& edges,
  const std::vector<my_custom_vertex>& vertices
) noexcept;

#endif // CREATE_CUSTOM_EDGES_AND_VERTICES_PATH_GRAPH_H
