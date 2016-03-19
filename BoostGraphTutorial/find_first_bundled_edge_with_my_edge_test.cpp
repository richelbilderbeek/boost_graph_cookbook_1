#include "find_first_bundled_edge_with_my_edge.h"
#include "find_first_bundled_edge_with_my_edge_demo.impl"
#include <boost/test/unit_test.hpp>

#include "create_bundled_edges_and_vertices_k3_graph.h"

BOOST_AUTO_TEST_CASE(find_first_bundled_edge_with_my_edge_thorough)
{
  {
    const auto g = create_bundled_edges_and_vertices_k3_graph();
    const auto ed = find_first_bundled_edge_with_my_edge(
      my_bundled_edge("Oxygen","Air",1.0,2.0),
      g
    );
    BOOST_CHECK(boost::source(ed,g) != boost::target(ed,g));
  }
}

