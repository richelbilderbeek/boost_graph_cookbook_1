#include "add_named_edge_between_vertices_demo.impl"

#include "add_named_edge_between_vertices.h"

#include <cassert>

#include "create_empty_undirected_named_edges_and_vertices_graph.h"
#include "add_named_edge_between_vertices.h"
#include "add_named_vertex.h"

void add_named_edge_between_vertices_test() noexcept
{
  {
    auto g = create_empty_undirected_named_edges_and_vertices_graph();
    const auto from = add_named_vertex("Bert", g);
    const auto to = add_named_vertex("Ernie", g);
    add_named_edge_between_vertices("Friends", from, to, g);
    assert(boost::num_edges(g) == 1);
  }
  add_named_edge_between_vertices_demo();
}

