#ifndef CREATE_EMPTY_DIRECTED_GRAPH_WITH_GRAPH_NAME_H
#define CREATE_EMPTY_DIRECTED_GRAPH_WITH_GRAPH_NAME_H

#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS,
  boost::no_property, boost::no_property,
  boost::property<boost::graph_name_t, std::string>>
create_empty_directed_graph_with_graph_name() noexcept;

#endif // CREATE_EMPTY_DIRECTED_GRAPH_WITH_GRAPH_NAME_H
