#include "load_undirected_named_edges_and_vertices_graph_from_dot.h"

#include "load_undirected_named_edges_and_vertices_graph_from_dot.impl"

#include "load_undirected_named_edges_and_vertices_graph_from_dot_demo.impl"

#include "copy_file.h"
#include <iostream>

#include "create_named_edges_and_vertices_k3_graph.h"
#include "convert_dot_to_svg.h"
#include "save_named_edges_and_vertices_graph_to_dot.h"
#include "helper.h"

void load_undirected_named_edges_and_vertices_graph_from_dot_test() noexcept
{
  //Create another graph by loading it, then save it to .dot, convert that .dot to .svg
  {
    const auto g = create_named_edges_and_vertices_k3_graph();
    const std::string dot_filename{"load_undirected_named_edges_and_vertices_graph_from_dot_test_markov_chain.dot"};
    save_named_edges_and_vertices_graph_to_dot(g, dot_filename);
    const auto old_text = helper().file_to_vector(dot_filename);
    const auto h = load_undirected_named_edges_and_vertices_graph_from_dot(dot_filename);
    save_named_edges_and_vertices_graph_to_dot(h, dot_filename);
    const auto new_text = helper().file_to_vector(dot_filename);
    assert(old_text == new_text);
    assert(boost::num_edges(g) == boost::num_edges(h));
    assert(boost::num_vertices(g) == boost::num_vertices(h));
  }
  load_undirected_named_edges_and_vertices_graph_from_dot_demo();
  std::cout << __func__ << ": OK" << '\n';
}
