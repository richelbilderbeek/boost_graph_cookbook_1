#include "has_custom_vertex.h"
#include "has_custom_vertex_demo.impl"

#include <boost/test/unit_test.hpp>
#include "add_custom_vertex.h"
#include "create_empty_undirected_custom_vertices_graph.h"
#include "get_my_custom_vertexes.h"

BOOST_AUTO_TEST_CASE(has_custom_vertex_thorough)
{
  auto g = create_empty_undirected_custom_vertices_graph();

  BOOST_CHECK(
    !has_custom_vertex(
      [](const my_custom_vertex& v) { return v.get_name() == "absent name"; },
    g)
  );

  add_custom_vertex(my_custom_vertex("name", "description", 3.14, 3.14), g);

  BOOST_CHECK(
    has_custom_vertex(
      [](const my_custom_vertex& v)
      {
        return v.get_x() > 2.0;
      },
      g
    )
  );

  BOOST_CHECK(
    !has_custom_vertex(
      [](const my_custom_vertex& v)
      {
        return v.get_x() > 12324.0;
      },
      g
    )
  );
}
