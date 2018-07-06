#include "find_if_first_bundled_vertex.h"
#include "find_if_first_bundled_vertex_demo.impl"

#include "create_bundled_vertices_k2_graph.h"
#include "create_empty_directed_bundled_vertices_graph.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(find_if_first_bundled_vertex_thorough)
{
  const auto g = create_bundled_vertices_k2_graph();
  BOOST_CHECK(has_bundled_vertex_with_my_vertex(
    my_bundled_vertex("Me", "Myself", 1.0, 2.0), g));
  const auto vd = find_if_first_bundled_vertex(
    g, [](const my_bundled_vertex& v){ return v.get_y() < 2.5; } );
  BOOST_CHECK(out_degree(vd, g) == 1); // not boost::out_degree
  BOOST_CHECK(in_degree(vd, g) == 1); // not boost::in_degree
}

BOOST_AUTO_TEST_CASE(
  find_if_first_bundled_vertex_when_vertex_is_absent)
{
  const auto g = create_empty_directed_bundled_vertices_graph();
  const auto pred = [](const my_bundled_vertex& v){ return v.get_y() == 0.0; };
  BOOST_CHECK_THROW(
    find_if_first_bundled_vertex(g,  pred),
    std::invalid_argument
  );
}
