#include "add_edge_between_named_vertices_demo.impl"

#include "add_edge_between_named_vertices.h"

#include <cassert>

#include "create_empty_undirected_named_vertices_graph.h"
#include "add_named_vertex.h"

void add_edge_between_named_vertices_test() noexcept
{
  {
    auto g = create_empty_undirected_named_vertices_graph();
    add_named_vertex("Bert", g);
    add_named_vertex("Ernie", g);
    add_edge_between_named_vertices("Bert", "Ernie", g);
    assert(boost::num_edges(g) == 1);
  }
  add_edge_between_named_vertices_demo();
}

