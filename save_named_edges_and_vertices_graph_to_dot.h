#ifndef SAVE_NAMED_EDGES_AND_VERTICES_GRAPH_TO_DOT
#define SAVE_NAMED_EDGES_AND_VERTICES_GRAPH_TO_DOT

#include <string>
#include <fstream>
#include <boost/graph/graphviz.hpp>
#include <boost/graph/properties.hpp>

#include "get_edge_names.h"
#include "get_vertex_names.h"

///Save a graph with named vertices to a .dot file
template <typename graph>
void save_named_edges_and_vertices_graph_to_dot(const graph& g, const std::string& filename)
{
  std::ofstream f(filename);
  const auto vertex_names = get_vertex_names(g);
  const auto edge_name_map = boost::get(boost::edge_name,g);
  boost::write_graphviz(
    f,
    g,
    boost::make_label_writer(&vertex_names[0]),
    [edge_name_map](std::ostream& out, const auto& e) {
      out << "[label=" << edge_name_map[e] << "]";
    }
  );
}

void save_named_edges_and_vertices_graph_to_dot_test() noexcept;

#endif // SAVE_NAMED_EDGES_AND_VERTICES_GRAPH_TO_DOT

