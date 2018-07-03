#ifndef CREATE_NAMED_VERTICES_PETERSEN_GRAPH_H
#define CREATE_NAMED_VERTICES_PETERSEN_GRAPH_H

#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<
    boost::vertex_name_t, std::string
  >
>
create_text_vertices_petersen_graph() noexcept;

#endif // CREATE_NAMED_VERTICES_PETERSEN_GRAPH_H
