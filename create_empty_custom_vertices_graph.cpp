#include "create_empty_custom_vertices_graph.h"

#include <iostream>

#include "get_n_edges.h"
#include "get_n_vertices.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<
    boost::vertex_custom_type_t,my_vertex
  >
>
create_empty_custom_vertices_graph() noexcept
{
  using graph = boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<
    boost::vertex_custom_type_t,my_vertex
    >
  >;

  graph g;
  return g;
}


void create_empty_custom_vertices_graph_test() noexcept
{
  const auto g = create_empty_custom_vertices_graph();
  assert(get_n_edges(g) == 0);
  assert(get_n_vertices(g) == 0);
  std::cout << __func__ << ": OK" << '\n';
}
