#include "count_vertices_with_selectedness.h"
#include "count_vertices_with_selectedness_demo.impl"

#include <boost/test/unit_test.hpp>

#include "add_custom_and_selectable_vertex.h"
#include "create_empty_undirected_custom_and_selectable_vertices_graph.h"

BOOST_AUTO_TEST_CASE(count_vertices_with_selectedness_thorough)
{
  auto g = create_empty_undirected_custom_and_selectable_vertices_graph();
  add_custom_and_selectable_vertex(my_custom_vertex("A"), true, g);
  add_custom_and_selectable_vertex(my_custom_vertex("B"), false, g);
  add_custom_and_selectable_vertex(my_custom_vertex("C"), true, g);
  BOOST_CHECK_EQUAL(count_vertices_with_selectedness(true, g), 2);
  BOOST_CHECK_EQUAL(count_vertices_with_selectedness(false, g), 1);
}

BOOST_AUTO_TEST_CASE(count_vertices_with_selectedness_of_another_type)
{
  using another_vertex = std::string;
  using another_graph
    = boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
      boost::property<boost::vertex_custom_type_t, another_vertex,
        boost::property<boost::vertex_is_selected_t, bool>>>;
  another_graph g;
  add_custom_and_selectable_vertex(another_vertex("A"), true, g);
  BOOST_CHECK_EQUAL(count_vertices_with_selectedness(true, g), 1);
}
