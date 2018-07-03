#include "add_text_edge_between_vertices.h"
#include "add_text_edge_between_vertices_demo.impl"

#include <boost/test/unit_test.hpp>

#include "add_text_edge_between_vertices.h"
#include "add_text_vertex.h"
#include "create_empty_undirected_text_edges_and_vertices_graph.h"

BOOST_AUTO_TEST_CASE(add_text_edge_between_vertices_add_one)
{
  auto g = create_empty_undirected_text_edges_and_vertices_graph();
  const auto from = add_text_vertex("Bert", g);
  const auto to = add_text_vertex("Ernie", g);
  add_text_edge_between_vertices("Friends", from, to, g);
  BOOST_CHECK(boost::num_edges(g) == 1);
}
