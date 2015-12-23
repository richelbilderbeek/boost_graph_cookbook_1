#include "set_vertex_names.h"

#include <iostream>

#include "create_named_vertices_k2_graph.h"
#include "get_vertex_names.h"


void set_vertex_names_test() noexcept
{
  //Named K2 graph
  {
    auto g = create_named_vertices_k2_graph();
    const std::vector<std::string> vertex_names{"alpha", "beta"};
    set_vertex_names(g,vertex_names);
    assert(get_vertex_names(g) == vertex_names);
  }
  std::cout << __func__ << ": OK" << '\n';
}
