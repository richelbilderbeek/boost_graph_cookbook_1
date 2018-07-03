#ifndef CREATE_PETERSEN_GRAPH_H
#define CREATE_PETERSEN_GRAPH_H

#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS>
create_petersen_graph() noexcept;

#endif // CREATE_PETERSEN_GRAPH_H
