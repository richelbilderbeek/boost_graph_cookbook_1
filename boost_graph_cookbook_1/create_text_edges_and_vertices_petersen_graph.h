#ifndef CREATE_TEXT_EDGES_AND_VERTICES_PETERSEN_GRAPH_H
#define CREATE_TEXT_EDGES_AND_VERTICES_PETERSEN_GRAPH_H

#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, std::string,
  std::string>
create_text_edges_and_vertices_petersen_graph();

#endif // CREATE_TEXT_EDGES_AND_VERTICES_PETERSEN_GRAPH_H
