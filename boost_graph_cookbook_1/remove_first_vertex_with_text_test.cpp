#include "remove_first_vertex_with_text.h"
#include "remove_first_vertex_with_text_demo.impl"

#include <boost/test/unit_test.hpp>
#include "create_text_vertices_k2_graph.h"
#include "create_empty_undirected_text_vertices_graph.h"
#include "clear_first_vertex_with_text.h"
#include "get_vertex_texts.h"

BOOST_AUTO_TEST_CASE(test_remove_first_vertex_with_text_thorough)
{
  auto g = create_text_vertices_k2_graph();
  BOOST_CHECK(boost::num_edges(g) == 1);
  BOOST_CHECK(boost::num_vertices(g) == 2);
  clear_first_vertex_with_text("My computer",g);
  remove_first_vertex_with_text("My computer",g);
  BOOST_CHECK(boost::num_edges(g) == 0);
  BOOST_CHECK(boost::num_vertices(g) == 1);
}

BOOST_AUTO_TEST_CASE(test_remove_first_vertex_with_text_for_vertex_that_does_not_exist)
{
  //Note: if using 'create_empty_*directed*_text_vertices_graph',
  //'degree' in 'remove_first_vertex_with_text' will give an error
  auto g = create_empty_undirected_text_vertices_graph();
  const std::string text{"Non-existing vertex text"};
  assert(!has_vertex_with_text(text, g));
  BOOST_CHECK_THROW(
    remove_first_vertex_with_text(text,g),
    std::invalid_argument
  );
}

BOOST_AUTO_TEST_CASE(test_remove_first_vertex_with_text_for_vertex_that_is_still_connected)
{
  auto g = create_text_vertices_k2_graph();
  const auto text = get_vertex_texts(g).front();
  const auto vd = find_first_vertex_with_text(text,g);
  assert(degree(vd,g) != 0);
  BOOST_CHECK_THROW(
    remove_first_vertex_with_text(text,g),
    std::invalid_argument
  );
}
