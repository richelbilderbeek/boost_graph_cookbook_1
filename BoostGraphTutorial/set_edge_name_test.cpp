#include "set_edge_name.h"
#include "set_edge_name_demo.impl"

#include <boost/test/unit_test.hpp>
#include "add_named_edge.h"
#include "create_empty_undirected_named_edges_and_vertices_graph.h"
#include "find_first_edge_with_name.h"
#include "get_edge_name.h"

BOOST_AUTO_TEST_CASE(set_edge_name_thorough)
{
  auto g = create_empty_undirected_named_edges_and_vertices_graph();
  const std::string old_name{"Dex"};
  add_named_edge(old_name, g);
  const auto vd = find_first_edge_with_name(old_name, g);
  BOOST_CHECK(get_edge_name(vd, g) == old_name);
  const std::string new_name{"Diggy"};
  set_edge_name(new_name, vd, g);
  BOOST_CHECK(get_edge_name(vd, g) == new_name);

  
}
