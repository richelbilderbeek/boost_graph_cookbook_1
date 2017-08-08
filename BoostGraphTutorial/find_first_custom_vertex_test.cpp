#include "find_first_custom_vertex.h"
#include "find_first_custom_vertex_demo.impl"

#include <boost/test/unit_test.hpp>
#include "create_empty_directed_custom_vertices_graph.h"
#include "create_custom_vertices_k2_graph.h"

BOOST_AUTO_TEST_CASE(find_first_custom_vertex_thorough)
{
  const auto g = create_custom_vertices_k2_graph();
  {
    //Find A by name
    const auto vd = find_first_custom_vertex(
      g, [](const my_custom_vertex& v)
      {
        return v.get_name() == "A";
      }
    );
    BOOST_CHECK(get_my_custom_vertex(vd, g).get_description() == "source");
  }
  {
    //Find B by x coordinat
    const auto vd = find_first_custom_vertex(
      g, [](const my_custom_vertex& v)
      {
        return v.get_x() > 3.0;
      }
    );
    BOOST_CHECK(get_my_custom_vertex(vd, g).get_name() == "B");
  }
}

BOOST_AUTO_TEST_CASE(find_first_custom_vertex_when_vertex_is_absent)
{
  const auto g = create_empty_directed_custom_vertices_graph();

  BOOST_CHECK_THROW(
    find_first_custom_vertex(
      g, [](const my_custom_vertex& v)
      {
        return v.get_name() == "absent";
      }
    ),
    std::invalid_argument
  );
}

