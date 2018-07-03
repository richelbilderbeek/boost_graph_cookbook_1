#ifndef CREATE_TEXT_VERTICES_PATH_GRAPH_H
#define CREATE_TEXT_VERTICES_PATH_GRAPH_H

#include <vector>
#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  std::string
>
create_text_vertices_path_graph(
    const std::vector<std::string>& names
) noexcept;

#endif // CREATE_TEXT_VERTICES_PATH_GRAPH_H
