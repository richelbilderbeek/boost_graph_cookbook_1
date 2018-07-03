#include "get_vertex_selectednesses.h"
#include "get_vertex_selectednesses_demo.impl"

#include <boost/test/unit_test.hpp>

#include "add_custom_and_selectable_vertex.h"
#include "create_empty_undirected_custom_and_selectable_vertices_graph.h"
#include "create_empty_undirected_named_vertices_graph.h"
#include "create_k2_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"
#include "create_named_vertices_k2_graph.h"

BOOST_AUTO_TEST_CASE(get_vertex_selectednesses_thorough)
{
  // Named K2 graph
  {
    auto g = create_empty_undirected_custom_and_selectable_vertices_graph();
    add_custom_and_selectable_vertex(my_custom_vertex{ "Chip" }, true, g);
    add_custom_and_selectable_vertex(my_custom_vertex{ "Chip" }, false, g);
    const std::vector<bool> expected_selectednesses{ true, false };
    const std::vector<bool> vertex_selectednesses{ get_vertex_selectednesses(
      g) };
    BOOST_CHECK(expected_selectednesses == vertex_selectednesses);
  }
}
