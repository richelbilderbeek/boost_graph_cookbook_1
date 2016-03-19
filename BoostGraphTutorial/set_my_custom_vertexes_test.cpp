#include "set_my_custom_vertexes.h"
//#include "set_my_custom_vertexes_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_custom_vertices_k2_graph.h"
#include "get_my_custom_vertexes.h"

BOOST_AUTO_TEST_CASE(set_my_custom_vertexes_thorough)
{
  //Named K2 graph
  {
    auto g = create_custom_vertices_k2_graph();
    const std::vector<my_custom_vertex> my_custom_vertexes{
      my_custom_vertex("alpha"),
      my_custom_vertex("beta")
    };
    BOOST_CHECK(get_my_custom_vertexes(g) != my_custom_vertexes);
    set_my_custom_vertexes(g,my_custom_vertexes);
    BOOST_CHECK(get_my_custom_vertexes(g) == my_custom_vertexes);
  }

  
}
