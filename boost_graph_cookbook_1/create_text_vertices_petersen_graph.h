#ifndef CREATE_TEXT_VERTICES_PETERSEN_GRAPH_H
#define CREATE_TEXT_VERTICES_PETERSEN_GRAPH_H

#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, std::string>
create_text_vertices_petersen_graph() noexcept;

#endif // CREATE_TEXT_VERTICES_PETERSEN_GRAPH_H
