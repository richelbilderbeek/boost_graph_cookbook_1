#include "has_bundled_edge_with_my_edge.h"
#include "has_bundled_edge_with_my_edge_demo.impl"

#include <boost/test/unit_test.hpp>
#include "add_bundled_edge.h"
#include "create_bundled_edges_and_vertices_k3_graph.h"

BOOST_AUTO_TEST_CASE(has_bundled_edge_with_my_edge_thorough)
{
  {
    auto g
      = create_bundled_edges_and_vertices_k3_graph();
    BOOST_CHECK(
      has_bundled_edge_with_my_edge(
        my_bundled_edge("Oxygen","Air",1.0,2.0),g
      )
    );
  }
}
