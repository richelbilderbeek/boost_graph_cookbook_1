#include "select_random_vertex.h"
#include "select_random_vertex_demo.impl"

#include "add_custom_and_selectable_vertex.h"
#include "add_custom_edge.h"
#include "count_vertices_with_selectedness.h"
#include "create_empty_undirected_custom_and_selectable_edges_and_vertices_graph.h"
#include "create_empty_undirected_custom_edges_and_vertices_graph.h"
#include "find_first_custom_edge_with_my_edge.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(select_random_vertex_thorough)
{
  const int seed{ 42 };
  std::mt19937 rng_engine(seed);
  auto g
    = create_empty_undirected_custom_and_selectable_edges_and_vertices_graph();
  add_custom_and_selectable_vertex(my_custom_vertex(), false, g);
  BOOST_CHECK(count_vertices_with_selectedness(true, g) == 0);
  select_random_vertex(g, rng_engine);
  BOOST_CHECK(count_vertices_with_selectedness(true, g) == 1);
}

BOOST_AUTO_TEST_CASE(select_random_vertex_in_empty_graph)
{
  const int seed{ 42 };
  std::mt19937 rng_engine(seed);
  auto g
    = create_empty_undirected_custom_and_selectable_edges_and_vertices_graph();
  BOOST_CHECK_THROW(select_random_vertex(g, rng_engine), std::invalid_argument);
}
