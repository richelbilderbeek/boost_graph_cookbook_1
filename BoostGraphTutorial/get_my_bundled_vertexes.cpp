#include "get_my_bundled_vertexes.h"
//#include "get_my_bundled_vertexes_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_bundled_vertices_k2_graph.h"

BOOST_AUTO_TEST_CASE(get_my_bundled_vertexes_thorough)
{
  {
    const auto g = create_bundled_vertices_k2_graph();
    const std::vector<my_bundled_vertex> expected_my_vertexes{
      my_bundled_vertex("Me","Myself",1.0,2.0),
      my_bundled_vertex("My computer","Not me",3.0,4.0)
    };
    const std::vector<my_bundled_vertex> vertexes{
      get_my_bundled_vertexes(g)
    };
    BOOST_CHECK(expected_my_vertexes == vertexes);
  }
  
}
