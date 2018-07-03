#include "set_edge_selectedness.h"
#include "set_edge_selectedness_demo.impl"

#include <boost/test/unit_test.hpp>

#include "add_custom_and_selectable_edge.h"
#include "add_custom_edge.h"
#include "create_empty_undirected_custom_and_selectable_edges_and_vertices_graph.h"
#include "find_first_custom_edge_with_my_edge.h"
#include "get_edge_selectedness.h"

BOOST_AUTO_TEST_CASE(set_edge_selectedness_thorough)
{
  {
    auto g
      = create_empty_undirected_custom_and_selectable_edges_and_vertices_graph();
    const my_custom_edge edge{ "Dex" };
    const auto ed = add_custom_and_selectable_edge(edge, true, g);
    BOOST_CHECK(get_edge_selectedness(ed, g) == true);
    set_edge_selectedness(false, ed, g);
    BOOST_CHECK(get_edge_selectedness(ed, g) == false);
  }
}
