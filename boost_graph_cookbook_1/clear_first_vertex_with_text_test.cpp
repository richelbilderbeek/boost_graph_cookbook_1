#include "clear_first_vertex_with_text.h"
#include "clear_first_vertex_with_text_demo.impl"

#include <boost/test/unit_test.hpp>
#include "add_textd_vertex.h"
#include "create_textd_vertices_k2_graph.h"

BOOST_AUTO_TEST_CASE(clear_first_vertex_with_text_on_textd_vertices_k2_graph)
{
  auto g = create_textd_vertices_k2_graph();
  BOOST_CHECK(boost::num_edges(g) == 1);
  clear_first_vertex_with_text("My computer",g);
  BOOST_CHECK(boost::num_edges(g) == 0);
}

BOOST_AUTO_TEST_CASE(clear_first_vertex_with_text_with_another_type)
{
  using another_text = int;
  using another_graph = boost::adjacency_list<
    boost::vecS,
    boost::vecS,
    boost::undirectedS,
    boost::property<boost::vertex_text_t,another_text>
  >;
  another_graph g;
  const another_text text{42};
  const auto vd_a = add_textd_vertex(text, g);
  const auto vd_b = add_textd_vertex(text, g);
  boost::add_edge(vd_a, vd_b, g);
  BOOST_CHECK(boost::num_edges(g) == 1);
  clear_first_vertex_with_text(text,g);
  BOOST_CHECK(boost::num_edges(g) == 0);
}
