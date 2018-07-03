#include "set_my_bundled_vertexes.h"
//#include "set_my_bundled_vertexes_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_bundled_vertices_k2_graph.h"
#include "get_my_bundled_vertexes.h"

BOOST_AUTO_TEST_CASE(set_my_bundled_vertexes_thorough)
{
  // Named K2 graph
  {
    auto g = create_bundled_vertices_k2_graph();
    const std::vector<my_bundled_vertex> my_vertexes{
      my_bundled_vertex("alpha"), my_bundled_vertex("beta")
    };
    BOOST_CHECK(get_my_bundled_vertexes(g) != my_vertexes);
    set_my_bundled_vertexes(g, my_vertexes);
    BOOST_CHECK(get_my_bundled_vertexes(g) == my_vertexes);
  }
}
