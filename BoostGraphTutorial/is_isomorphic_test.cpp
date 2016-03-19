#include "is_isomorphic.h"
#include "is_isomorphic_demo.impl"


#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>
#include "create_path_graph.h"
#include "create_k2_graph.h"
#include "create_k3_graph.h"

BOOST_AUTO_TEST_CASE(is_isomorphic_thorough)
{
  //Basic tests: K2 == path graph of 2 vertices
  {
    const auto g = create_path_graph(2);
    const auto h = create_k2_graph();
    BOOST_CHECK(is_isomorphic(g,h));
  }
  //Basic tests: K3 != path graph of 3 vertices
  {
    const auto g = create_path_graph(3);
    const auto h = create_k3_graph();
    BOOST_CHECK( is_isomorphic(g,g));
    BOOST_CHECK( is_isomorphic(h,h));
    BOOST_CHECK(!is_isomorphic(g,h));
  }
}
