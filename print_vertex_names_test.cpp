#include "print_vertex_names.h"

#include <iostream>

#include "create_k2_graph.h"
#include "create_named_vertices_k2_graph.h"
#include "create_router_network_graph.h"

void print_vertex_names_test() noexcept
{
  {
    //Should not compile, due to error: forming reference to void
    //const auto g = create_k2_graph();
    //print_vertex_names(g);
  }
  {
    const auto g = create_named_vertices_k2_graph();
    print_vertex_names(g);
  }
  {
    const auto g = create_router_network_graph();
    print_vertex_names(g);
  }
  std::cout << __func__ << ": OK" << '\n';
}
