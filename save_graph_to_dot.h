#ifndef SAVE_GRAPH_TO_DOT_H
#define SAVE_GRAPH_TO_DOT_H

#include <fstream>
#include <boost/graph/graphviz.hpp>

///Save a graph to a .dot file
template <typename graph>
void save_graph_to_dot(const graph& g, const std::string& filename)
{
  std::ofstream f(filename);
  boost::write_graphviz(f,g);
}

void save_graph_to_dot_test() noexcept;

#endif // SAVE_GRAPH_TO_DOT_H
