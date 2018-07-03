#ifndef CREATE_TEXT_EDGES_AND_VERTICES_PATH_GRAPH_H
#define CREATE_TEXT_EDGES_AND_VERTICES_PATH_GRAPH_H

#include <vector>
#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  std::string,
  std::string
>
create_text_edges_and_vertices_path_graph(
  const std::vector<std::string>& edge_names,
  const std::vector<std::string>& vertex_names
);

#endif // CREATE_TEXT_EDGES_AND_VERTICES_PATH_GRAPH_H
