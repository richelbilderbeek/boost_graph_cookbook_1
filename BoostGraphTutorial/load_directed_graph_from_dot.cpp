#include "load_directed_graph_from_dot.h"

#include "load_directed_graph_from_dot.impl"

#include "load_directed_graph_from_dot_demo.impl"

#include "copy_file.h"
#include <iostream>

#include "create_markov_chain.h"
#include "convert_dot_to_svg.h"

void load_directed_graph_from_dot_test() noexcept
{
  //Create graphs, save it to dot
  //Create another graph by loading it, then save it to .dot, convert that .dot to .svg
  {
    const auto g = create_markov_chain();
    const std::string dot_filename{"load_directed_graph_from_dot_test_markov_chain.dot"};
    save_graph_to_dot(g, dot_filename);
    const auto h = load_directed_graph_from_dot(dot_filename);
    save_graph_to_dot(h, dot_filename);
    assert(boost::num_edges(g) == boost::num_edges(h));
    assert(boost::num_vertices(g) == boost::num_vertices(h));
  }
  load_directed_graph_from_dot_demo();
  
}
