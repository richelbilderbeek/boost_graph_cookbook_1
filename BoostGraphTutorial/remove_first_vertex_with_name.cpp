#include "remove_first_vertex_with_name.h"
#include "remove_first_vertex_with_name_demo.impl"

#include <boost/test/unit_test.hpp>
#include "create_named_vertices_k2_graph.h"
#include "clear_first_vertex_with_name.h"

BOOST_AUTO_TEST_CASE(remove_first_vertex_with_name_thorough)
{
  //Clean behavior
  {
    auto g = create_named_vertices_k2_graph();
    BOOST_CHECK(boost::num_edges(g) == 1);
    BOOST_CHECK(boost::num_vertices(g) == 2);
    clear_first_vertex_with_name("My computer",g);
    remove_first_vertex_with_name("My computer",g);
    BOOST_CHECK(boost::num_edges(g) == 0);
    BOOST_CHECK(boost::num_vertices(g) == 1);
  }
  #ifdef REMOVE_VERTEX_WITHOUT_CLEARING
  //Remove the vertex without clearing
  {
    auto g = create_named_vertices_k2_graph();
    BOOST_CHECK(boost::num_edges(g) == 1);
    BOOST_CHECK(boost::num_vertices(g) == 2);
    remove_first_vertex_with_name("My computer",g); //Will keep the edge??? Will be checked by assert
    BOOST_CHECK(!has_vertex_with_name("My computer",g));
    BOOST_CHECK(boost::num_edges(g) == 1);
    BOOST_CHECK(boost::num_vertices(g) == 1);
  }
  #endif // REMOVE_VERTEX_WITHOUT_CLEARING
}
