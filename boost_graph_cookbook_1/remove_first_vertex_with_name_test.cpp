#include "remove_first_vertex_with_name.h"
#include "remove_first_vertex_with_name_demo.impl"

#include "clear_first_vertex_with_name.h"
#include "create_empty_undirected_named_vertices_graph.h"
#include "create_named_vertices_k2_graph.h"
#include "get_vertex_names.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_remove_first_vertex_with_name_thorough)
{
  auto g = create_named_vertices_k2_graph();
  BOOST_CHECK(boost::num_edges(g) == 1);
  BOOST_CHECK(boost::num_vertices(g) == 2);
  clear_first_vertex_with_name("My computer", g);
  remove_first_vertex_with_name("My computer", g);
  BOOST_CHECK(boost::num_edges(g) == 0);
  BOOST_CHECK(boost::num_vertices(g) == 1);
}

BOOST_AUTO_TEST_CASE(
  test_remove_first_vertex_with_name_for_vertex_that_does_not_exist)
{
  // Note: if using 'create_empty_*directed*_named_vertices_graph',
  //'degree' in 'remove_first_vertex_with_name' will give an error
  auto g = create_empty_undirected_named_vertices_graph();
  const std::string name{ "Non-existing vertex name" };
  assert(!has_vertex_with_name(name, g));
  BOOST_CHECK_THROW(
    remove_first_vertex_with_name(name, g), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(
  test_remove_first_vertex_with_name_for_vertex_that_is_still_connected)
{
  auto g = create_named_vertices_k2_graph();
  const auto name = get_vertex_names(g).front();
  const auto vd = find_first_vertex_with_name(name, g);
  assert(degree(vd, g) != 0);
  BOOST_CHECK_THROW(
    remove_first_vertex_with_name(name, g), std::invalid_argument);
}
