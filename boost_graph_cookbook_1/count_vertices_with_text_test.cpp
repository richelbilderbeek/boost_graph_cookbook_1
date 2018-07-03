#include "count_vertices_with_text.h"
#include "count_vertices_with_text_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_empty_undirected_textd_vertices_graph.h"
#include "add_textd_vertex.h"

BOOST_AUTO_TEST_CASE(count_vertices_with_text_thorough)
{
  auto g = create_empty_undirected_textd_vertices_graph();
  add_textd_vertex("Rex", g);
  BOOST_CHECK_EQUAL(count_vertices_with_text("Rex", g), 1);
  BOOST_CHECK_EQUAL(count_vertices_with_text("Nebular", g), 0);
}

BOOST_AUTO_TEST_CASE(count_vertices_with_text_of_another_type)
{
  using another_text = int;
  using another_graph = boost::adjacency_list<
    boost::vecS,
    boost::vecS,
    boost::undirectedS,
    boost::property<
      boost::vertex_text_t, another_text
    >
  >;
  another_graph g;
  const another_text text_present{42};
  const another_text text_absent{314};
  add_textd_vertex(text_present, g);
  BOOST_CHECK_EQUAL(count_vertices_with_text(text_present, g), 1);
  BOOST_CHECK_EQUAL(count_vertices_with_text(text_absent, g), 0);
}
