#include "get_edge_name.h"
#include "get_edge_name_demo.impl"

#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>
#include "create_empty_undirected_named_edges_and_vertices_graph.h"
#include "add_named_edge.h"
#include "find_first_edge_with_name.h"

BOOST_AUTO_TEST_CASE(get_edge_name_thorough)
{
  auto g = create_empty_undirected_named_edges_and_vertices_graph();
  const std::string name{"Dex"};
  add_named_edge(name, g);
  const auto vd = find_first_edge_with_name(name,g);
  BOOST_CHECK(get_edge_name(vd,g) == name);
}
