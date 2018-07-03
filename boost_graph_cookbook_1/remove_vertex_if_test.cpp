#include "remove_vertex_if.h"
#include "remove_vertex_if_demo.impl"

#include "create_path_graph.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(remove_vertex_on_path_graph)
{
  //
  // A---B---C
  //
  // becomes
  //
  // A       C
  //
  auto g = create_path_graph(3);
  assert(boost::num_vertices(g) == 3);
  assert(boost::num_edges(g) == 2);
  remove_vertex_if(
    [](const auto vd, const auto& my_graph) {
      return boost::degree(vd, my_graph) == 2;
    },
    g);
  BOOST_CHECK_EQUAL(boost::num_vertices(g), 2);
  BOOST_CHECK_EQUAL(boost::num_edges(g), 0);
}
