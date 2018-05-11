#include "count_vertices_with_name.h"
#include "count_vertices_with_name_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_empty_undirected_named_vertices_graph.h"
#include "add_named_vertex.h"

BOOST_AUTO_TEST_CASE(count_vertices_with_name_thorough)
{
  auto g = create_empty_undirected_named_vertices_graph();
  add_named_vertex("Rex", g);
  BOOST_CHECK_EQUAL(count_vertices_with_name("Rex", g), 1);
  BOOST_CHECK_EQUAL(count_vertices_with_name("Nebular", g), 0);
}

BOOST_AUTO_TEST_CASE(count_vertices_with_name_of_another_type)
{
  using another_name = int;
  using another_graph = boost::adjacency_list<
    boost::vecS,
    boost::vecS,
    boost::undirectedS,
    boost::property<
      boost::vertex_name_t, another_name
    >
  >;
  another_graph g;
  const another_name name_present{42};
  const another_name name_absent{314};
  add_named_vertex(name_present, g);
  BOOST_CHECK_EQUAL(count_vertices_with_name(name_present, g), 1);
  BOOST_CHECK_EQUAL(count_vertices_with_name(name_absent, g), 0);
}
