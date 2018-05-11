#include "get_vertex_out_degrees.h"
#include "get_vertex_out_degrees_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_k2_graph.h"
#include "create_named_vertices_k2_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"

BOOST_AUTO_TEST_CASE(get_vertex_out_degrees_thorough)
{
  //Undirected K2 graph
  {
    const auto g = create_k2_graph();

    const std::vector<int> expected_out_degrees{1,1};
    const std::vector<int> vertex_out_degrees{get_vertex_out_degrees(g)};
    BOOST_CHECK(expected_out_degrees == vertex_out_degrees);
  }
  //Undirected K3 graph
  {
    const auto g = create_named_edges_and_vertices_k3_graph();
    const std::vector<int> expected_out_degrees{2,2,2};
    const std::vector<int> vertex_out_degrees{get_vertex_out_degrees(g)};
    BOOST_CHECK(expected_out_degrees == vertex_out_degrees);
  }
}
