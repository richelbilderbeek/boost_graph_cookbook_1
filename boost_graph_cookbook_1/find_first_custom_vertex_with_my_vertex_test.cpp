#include "find_first_custom_vertex_with_my_vertex.h"
#include "find_first_custom_vertex_with_my_vertex_demo.impl"

#include "create_custom_vertices_k2_graph.h"
#include "create_empty_directed_custom_vertices_graph.h"
#include "has_custom_vertex_with_my_vertex.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(find_first_custom_vertex_with_my_vertex_thorough)
{
  const auto g = create_custom_vertices_k2_graph();
  BOOST_CHECK(has_custom_vertex_with_my_vertex(
    my_custom_vertex("A", "source", 0.0, 0.0), g));
  const auto vd = find_first_custom_vertex_with_my_vertex(
    my_custom_vertex("A", "source", 0.0, 0.0), g);
  BOOST_CHECK(out_degree(vd, g) == 1); // not boost::out_degree
  BOOST_CHECK(in_degree(vd, g) == 1); // not boost::in_degree
}

BOOST_AUTO_TEST_CASE(
  find_first_custom_vertex_with_my_vertex_when_vertex_is_absent)
{
  const auto g = create_empty_directed_custom_vertices_graph();
  const my_custom_vertex v;
  const my_custom_vertex w;
  assert(!has_custom_vertex_with_my_vertex(v, g));
  BOOST_CHECK_THROW(
    find_first_custom_vertex_with_my_vertex(v, g), std::invalid_argument);
  BOOST_CHECK_THROW(
    find_first_custom_vertex_with_my_vertex(w, g), std::invalid_argument);
}
