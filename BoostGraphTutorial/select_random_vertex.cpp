#include "select_random_vertex.h"

#include "select_random_vertex_demo.impl"

#include <iostream>
#include <cassert>

#include "create_empty_undirected_custom_edges_and_vertices_graph.h"
#include "add_custom_edge.h"
#include "find_first_custom_edge_with_my_edge.h"
#include "count_vertices_with_selectedness.h"

void select_random_vertex_test() noexcept
{
  {
    const int seed{42};
    std::mt19937 rng_engine(seed);
    auto g
      = create_empty_undirected_custom_and_selectable_edges_and_vertices_graph();
    add_custom_and_selectable_vertex(
      my_custom_vertex(), false, g
    );
    assert(count_vertices_with_selectedness(true, g) == 0);
    select_random_vertex(g, rng_engine);
    assert(count_vertices_with_selectedness(true, g) == 1);
  }
  select_random_vertex_demo();
}
