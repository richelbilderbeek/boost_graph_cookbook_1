#include "create_named_vertices_k2_graph_test.h"

#include <cassert>
#include "get_n_edges.h"
#include "get_n_vertices.h"
#include "create_named_vertices_k2_graph.h"

void create_named_vertices_k2_graph_test() noexcept
{
  const auto g = create_named_vertices_k2_graph();
  assert(get_n_edges(g) == 1);
  assert(get_n_vertices(g) == 2);

  std::cout << __func__ << ": OK" << '\n';
}

