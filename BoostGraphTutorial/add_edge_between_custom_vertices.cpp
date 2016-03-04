#include "add_edge_between_custom_vertices_demo.impl"

#include "add_edge_between_custom_vertices.h"

#include <cassert>

#include "create_empty_undirected_custom_vertices_graph.h"
#include "add_named_vertex.h"

void add_edge_between_custom_vertices_test() noexcept
{
  {
    auto g = create_empty_undirected_custom_vertices_graph();
    const my_custom_vertex va("Bert");
    const my_custom_vertex vb("Ernie");
    add_custom_vertex(va, g);
    add_custom_vertex(vb, g);
    add_edge_between_custom_vertices(va, vb, g);
    assert(boost::num_edges(g) == 1);
  }
  add_edge_between_custom_vertices_demo();
}

