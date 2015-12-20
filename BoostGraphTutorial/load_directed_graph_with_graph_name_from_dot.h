#ifndef LOAD_DIRECTED_GRAPH_WITH_GRAPH_NAMES_FROM_DOT_H
#define LOAD_DIRECTED_GRAPH_WITH_GRAPH_NAMES_FROM_DOT_H

#include <boost/graph/adjacency_list.hpp>
#include "install_vertex_custom_type.h"
#include "install_edge_custom_type.h"
#include "my_vertex.h"
#include "my_edge.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::no_property,
  boost::no_property,
  boost::property<
    boost::graph_name_t,std::string
  >
>
load_directed_graph_with_graph_name_from_dot(
  const std::string& dot_filename
);

void load_directed_graph_with_graph_name_from_dot_test() noexcept;


#endif // LOAD_DIRECTED_GRAPH_WITH_GRAPH_NAMES_FROM_DOT_H
