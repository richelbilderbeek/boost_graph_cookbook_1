#include "add_custom_and_selectable_edge_between_vertices_demo.impl"

#include "add_custom_and_selectable_edge_between_vertices.h"

#include <cassert>

#include "create_empty_undirected_custom_and_selectable_edges_and_vertices_graph.h"
#include "add_custom_and_selectable_edge_between_vertices.h"
#include "add_custom_vertex.h"

void add_custom_and_selectable_edge_between_vertices_test() noexcept
{
  {
    auto g = create_empty_undirected_custom_and_selectable_edges_and_vertices_graph();
    const auto from = add_custom_vertex(
      my_custom_vertex("Bert"), g
    );
    const auto to = add_custom_vertex(
      my_custom_vertex("Ernie"), g
    );
    add_custom_and_selectable_edge_between_vertices(
      my_custom_edge("Friends"), false, from, to, g
    );
    assert(boost::num_edges(g) == 1);
  }
  add_custom_and_selectable_edge_between_vertices_demo();
}

