#include "load_directed_bundled_vertices_graph_from_dot.h"

#include "load_directed_bundled_vertices_graph_from_dot.impl"

#include "load_directed_bundled_vertices_graph_from_dot_demo.impl"

#include "copy_file.h"
#include <iostream>

#include "create_bundled_vertices_markov_chain.h"
#include "convert_dot_to_svg.h"
#include "save_bundled_vertices_graph_to_dot.h"
#include "helper.h"
#include "my_bundled_vertex.h"
#include "create_nasty_directed_bundled_vertices_graph.h"
#include "get_sorted_bundled_vertex_my_vertexes.h"

void load_directed_bundled_vertices_graph_from_dot_test() noexcept
{
  //Basic tests: empty graph
  {
    const auto g = create_empty_directed_bundled_vertices_graph();
    const std::string filename{
      "load_directed_bundled_vertices_graph_from_dot_test.dot"
    };
    save_bundled_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_bundled_vertices_graph_from_dot(filename);
    assert(boost::num_edges(g) == boost::num_edges(h));
    assert(boost::num_vertices(g) == boost::num_vertices(h));
    assert(get_bundled_vertex_my_vertexes(g) == get_bundled_vertex_my_vertexes(h));
  }
  //Basic tests: graph with harder texts
  {
    //See: create_nasty_directed_bundled_vertices_graph
  }
  load_directed_bundled_vertices_graph_from_dot_demo();
  std::cout << __func__ << ": OK" << '\n';
}
