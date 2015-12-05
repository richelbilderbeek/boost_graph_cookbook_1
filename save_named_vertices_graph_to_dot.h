#ifndef SAVE_NAMED_VERTICES_GRAPH_TO_DOT_H
#define SAVE_NAMED_VERTICES_GRAPH_TO_DOT_H

#include <string>
#include <fstream>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/properties.hpp>

#include "get_vertex_names.h"

///Save a graph with named vertices to a .dot file
template <typename graph>
void save_named_vertices_graph_to_dot(const graph& g, const std::string& filename)
{
  std::ofstream f(filename);
  const auto names = get_vertex_names(g);
  boost::write_graphviz(f,g,boost::make_label_writer(&names[0]));
}


#endif // SAVE_NAMED_VERTICES_GRAPH_TO_DOT_H
