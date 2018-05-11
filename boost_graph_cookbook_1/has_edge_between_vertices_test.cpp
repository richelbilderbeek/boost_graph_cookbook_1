#include "has_edge_between_vertices.h"
#include "has_edge_between_vertices_demo.impl"


#include <boost/test/unit_test.hpp>


#include "create_named_vertices_k2_graph.h"
#include "create_k2_graph.h"
#include "create_markov_chain.h"
#include "find_first_vertex_with_name.h"
#include "get_vertex_descriptors.h"
#include "create_path_graph.h"
#include "has_edge_between_vertices.h"

BOOST_AUTO_TEST_CASE(has_edge_between_vertices_k2_graph)
{
  //undirected graph
  const auto g = create_k2_graph();
  const auto vd_1 = *vertices(g).first;
  const auto vd_2 = *(++vertices(g).first);
  BOOST_CHECK(!has_edge_between_vertices(vd_1, vd_1, g));
  BOOST_CHECK( has_edge_between_vertices(vd_1, vd_2, g));
  BOOST_CHECK( has_edge_between_vertices(vd_2, vd_1, g));
  BOOST_CHECK(!has_edge_between_vertices(vd_2, vd_2, g));
}

BOOST_AUTO_TEST_CASE(has_edge_between_vertices_markov_chain)
{
  //directed graph
  const auto g = create_markov_chain();
  const auto vd_1 = *vertices(g).first;
  const auto vd_2 = *(++vertices(g).first);
  BOOST_CHECK(has_edge_between_vertices(vd_1, vd_1, g));
  BOOST_CHECK(has_edge_between_vertices(vd_1, vd_2, g));
  BOOST_CHECK(has_edge_between_vertices(vd_2, vd_1, g));
  BOOST_CHECK(has_edge_between_vertices(vd_2, vd_2, g));
}


BOOST_AUTO_TEST_CASE(has_edge_between_vertices_named_k2_graph)
{
  const auto g = create_named_vertices_k2_graph();
  const auto vd_1 = find_first_vertex_with_name("Me", g);
  const auto vd_2 = find_first_vertex_with_name("My computer", g);
  BOOST_CHECK(has_edge_between_vertices(vd_1, vd_2, g));
}

BOOST_AUTO_TEST_CASE(has_edge_between_vertices_path_graph)
{
  //A three-vertex path graph has 4 edges (2 edges in 2 directions) to be detected

  // A --- B --- C
  const int n_vertices{3};
  const auto g = create_path_graph(n_vertices);
  const auto vds = get_vertex_descriptors(g);
  BOOST_CHECK(n_vertices == static_cast<int>(vds.size()));
  int cnt{0};
  for (int i=0; i!=n_vertices; ++i)
  {
    for (int j=0; j!=n_vertices; ++j)
    {
      if (has_edge_between_vertices(vds[i],vds[j], g)) ++cnt;
    }
  }
  BOOST_CHECK(cnt == 4);
}
