#include "find_first_custom_vertex_with_my_vertex.h"
#include "find_first_custom_vertex_with_my_vertex_demo.impl"

#include <boost/test/unit_test.hpp>


#include "create_custom_vertices_k2_graph.h"

BOOST_AUTO_TEST_CASE(find_first_custom_vertex_with_my_vertex_thorough)
{
  {
    const auto g = create_custom_vertices_k2_graph();
    BOOST_CHECK(has_custom_vertex_with_my_custom_vertex(my_custom_vertex("A","source",0.0,0.0), g));
    const auto vd = find_first_custom_vertex_with_my_vertex(my_custom_vertex("A","source",0.0,0.0), g);
    BOOST_CHECK(out_degree(vd,g) == 1); //not boost::out_degree
    BOOST_CHECK(in_degree(vd,g) == 1); //not boost::in_degree
  }
}

