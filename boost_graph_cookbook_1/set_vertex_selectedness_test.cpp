#include "set_vertex_selectedness.h"
#include "set_vertex_selectedness_demo.impl"

#include <boost/test/unit_test.hpp>

#include "add_custom_and_selectable_vertex.h"
#include "add_custom_edge.h"
#include "create_empty_undirected_custom_and_selectable_edges_and_vertices_graph.h"
#include "create_empty_undirected_custom_edges_and_vertices_graph.h"
#include "find_first_custom_edge_with_my_edge.h"
#include "get_vertex_selectedness.h"

BOOST_AUTO_TEST_CASE(set_vertex_selectedness_thorough)
{
  {
    auto g
      = create_empty_undirected_custom_and_selectable_edges_and_vertices_graph();
    const auto vd
      = add_custom_and_selectable_vertex(my_custom_vertex(), true, g);
    BOOST_CHECK(get_vertex_selectedness(vd, g) == true);
    set_vertex_selectedness(false, vd, g);
    BOOST_CHECK(get_vertex_selectedness(vd, g) == false);
    set_vertex_selectedness(true, vd, g);
    BOOST_CHECK(get_vertex_selectedness(vd, g) == true);
  }
}
