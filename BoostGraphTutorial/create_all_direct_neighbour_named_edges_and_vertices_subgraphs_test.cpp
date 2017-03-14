#include "create_all_direct_neighbour_named_edges_and_vertices_subgraphs.h"
#include "create_all_direct_neighbour_named_edges_and_vertices_subgraphs_demo.impl"

#include <boost/test/unit_test.hpp>
#include "create_named_edges_and_vertices_k2_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"
#include "create_named_edges_and_vertices_petersen_graph.h"
#include "create_named_edges_and_vertices_path_graph.h"
#include "has_edge_with_name.h"
#include "has_vertex_with_name.h"

BOOST_AUTO_TEST_CASE(create_all_direct_neighbour_named_edges_and_vertices_subgraphs_thorough)
{
  //K2
  {
    const auto v = create_all_direct_neighbour_named_edges_and_vertices_subgraphs(
      create_named_edges_and_vertices_k2_graph()
    );
    BOOST_CHECK(v.size() == 2);
    for (const auto g: v)
    {
      BOOST_CHECK(boost::num_vertices(g) == 2);
      BOOST_CHECK(boost::num_edges(g) == 1);
      const std::string va("x");
      const std::string vb("y");
      const std::string ea("between");
      BOOST_CHECK(has_vertex_with_name(va, g));
      BOOST_CHECK(has_vertex_with_name(vb, g));
      BOOST_CHECK(has_edge_with_name(ea, g));
    }
  }
  //K3
  {
    const auto v
      = create_all_direct_neighbour_named_edges_and_vertices_subgraphs(
        create_named_edges_and_vertices_k3_graph()
      );
    BOOST_CHECK(v.size() == 3);
    for (const auto g: v)
    {
      BOOST_CHECK(boost::num_vertices(g) == 3);
      BOOST_CHECK(boost::num_edges(g) == 3);
      const std::string va("top");
      const std::string vb("right");
      const std::string vc("left");
      const std::string ea("AB");
      const std::string eb("BC");
      const std::string ec("CA");
      BOOST_CHECK(has_vertex_with_name(va, g));
      BOOST_CHECK(has_vertex_with_name(vb, g));
      BOOST_CHECK(has_vertex_with_name(vc, g));
      BOOST_CHECK(has_edge_with_name(ea, g));
      BOOST_CHECK(has_edge_with_name(eb, g));
      BOOST_CHECK(has_edge_with_name(ec, g));
    }
  }
  //Path
  {
    const auto v = create_all_direct_neighbour_named_edges_and_vertices_subgraphs(
      create_named_edges_and_vertices_path_graph(
        {"1","2"}, {"A","B","C"}
      )
    );
    const int sz{3};
    BOOST_CHECK(sz == static_cast<int>(v.size()));
  }
  //Petersen Graph
  {
    const auto v = create_all_direct_neighbour_named_edges_and_vertices_subgraphs(create_named_edges_and_vertices_petersen_graph());
    BOOST_CHECK(v.size() == 10);
    for (const auto g: v)
    {
      BOOST_CHECK(boost::num_vertices(g) == 4);
      BOOST_CHECK(boost::num_edges(g) == 3);
    }
  }
}
