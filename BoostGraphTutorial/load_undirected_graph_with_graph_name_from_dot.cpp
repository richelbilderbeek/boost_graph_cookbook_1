#include "load_undirected_graph_with_graph_name_from_dot.h"

#include "load_undirected_graph_with_graph_name_from_dot.impl"

#include "load_undirected_graph_with_graph_name_from_dot_demo.impl"

#include "copy_file.h"
#include <iostream>

#include "create_k2_graph_with_graph_name.h"
#include "convert_dot_to_svg.h"
#include "helper.h"


void load_undirected_graph_with_graph_name_from_dot_test() noexcept
{
  {
    const auto g = create_k2_graph_with_graph_name();
    const std::string base_filename{"create_k2_graph_with_graph_name"};
    const std::string dot_filename{base_filename + ".dot"};
    save_graph_with_graph_name_to_dot(g, dot_filename);
    const auto h = load_undirected_graph_with_graph_name_from_dot(dot_filename);
    assert(boost::num_edges(g) == boost::num_edges(h));
    assert(boost::num_vertices(g) == boost::num_vertices(h));
    assert(get_graph_name(g) == get_graph_name(h));
  }
  load_undirected_graph_with_graph_name_from_dot_demo();
  
}
