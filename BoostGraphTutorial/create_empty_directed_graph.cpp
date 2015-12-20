#include "create_empty_directed_graph.h"

#include "create_empty_directed_graph.impl"

#include <iostream>



#include "get_graph_name.h"

#include "create_empty_directed_graph_demo.impl"

void create_empty_directed_graph_test() noexcept
{

  auto g = create_empty_directed_graph();
  assert(boost::num_edges(g) == 0);
  assert(boost::num_vertices(g) == 0);

  //Sure, can
  add_vertex(g);

  create_empty_directed_graph_demo();
  std::cout << __func__ << ": OK" << '\n';
}
