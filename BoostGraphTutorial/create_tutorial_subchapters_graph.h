#ifndef CREATE_TUTORIAL_SUBCHAPTERS_GRAPH_H
#define CREATE_TUTORIAL_SUBCHAPTERS_GRAPH_H

#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::property<boost::vertex_name_t,std::string>
>
create_tutorial_subchapters_graph() noexcept;

void create_tutorial_subchapters_graph_test() noexcept;

#endif // CREATE_TUTORIAL_SUBCHAPTERS_GRAPH_H
