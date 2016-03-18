#include "count_vertices_with_selectedness.h"
#include "count_vertices_with_selectedness_demo.impl"


#include <boost/test/unit_test.hpp>

#include "create_empty_undirected_custom_and_selectable_vertices_graph.h"
#include "add_custom_and_selectable_vertex.h"

BOOST_AUTO_TEST_CASE(count_vertices_with_selectedness_thorough)
{
  {
    auto g = create_empty_undirected_custom_and_selectable_vertices_graph();
    add_custom_and_selectable_vertex(
      my_custom_vertex("A"), true, g
    );
    add_custom_and_selectable_vertex(
      my_custom_vertex("B"), false, g
    );
    add_custom_and_selectable_vertex(
      my_custom_vertex("C"), true, g
    );
    BOOST_CHECK(count_vertices_with_selectedness( true, g) == 2);
    BOOST_CHECK(count_vertices_with_selectedness(false, g) == 1);
  }
}
