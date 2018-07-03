#ifndef CREATE_NAMED_VERTICES_PATH_GRAPH_H
#define CREATE_NAMED_VERTICES_PATH_GRAPH_H

#include <boost/graph/adjacency_list.hpp>
#include <vector>

boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
  boost::property<boost::vertex_name_t, std::string>>
create_named_vertices_path_graph(
  const std::vector<std::string>& names) noexcept;

#endif // CREATE_NAMED_VERTICES_PATH_GRAPH_H
