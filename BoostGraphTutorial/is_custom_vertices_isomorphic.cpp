#include "is_custom_vertices_isomorphic.h"
#include "is_custom_vertices_isomorphic_demo.impl"


#include <boost/test/unit_test.hpp>

#include "create_path_graph.h"
#include "create_k2_graph.h"
#include "create_k3_graph.h"
#include "create_custom_vertices_path_graph.h"

BOOST_AUTO_TEST_CASE(is_custom_vertices_isomorphic_thorough)
{
  {
    const auto g = create_custom_vertices_path_graph(
      {
        my_custom_vertex("Alpha"),
        my_custom_vertex("Beta"),
        my_custom_vertex("Gamma")
      }
    );
    const auto h = create_custom_vertices_path_graph(
      {
        my_custom_vertex("Alpha"),
        my_custom_vertex("Beta"),
        my_custom_vertex("Gamma")
      }
    );
    BOOST_CHECK( is_custom_vertices_isomorphic(g,h));
  }
  {
    const auto g = create_custom_vertices_path_graph(
      {
        my_custom_vertex("Alpha"),
        my_custom_vertex("Beta"),
        my_custom_vertex("Gamma")
      }
    );
    const auto h = create_custom_vertices_path_graph(
      {
        my_custom_vertex("Gamma"),
        my_custom_vertex("Beta"),
        my_custom_vertex("Alpha")
      }
    );
    BOOST_CHECK( is_custom_vertices_isomorphic(g,h));
  }
  {
    const auto g = create_custom_vertices_path_graph(
      {
        my_custom_vertex("Alpha"),
        my_custom_vertex("Beta"),
        my_custom_vertex("Gamma")
      }
    );
    const auto h = create_custom_vertices_path_graph(
      {
        my_custom_vertex("Alpha"),
        my_custom_vertex("Gamma"),
        my_custom_vertex("Beta")
      }
    );
    BOOST_CHECK( is_custom_vertices_isomorphic(g,g));
    BOOST_CHECK(!is_custom_vertices_isomorphic(g,h));
  }
}




