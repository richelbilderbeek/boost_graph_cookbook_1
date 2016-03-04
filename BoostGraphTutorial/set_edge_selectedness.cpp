#include "set_edge_selectedness.h"

#include "set_edge_selectedness_demo.impl"

#include <iostream>
#include <cassert>

#include "create_empty_undirected_custom_and_selectable_edges_and_vertices_graph.h"
#include "add_custom_edge.h"
#include "find_first_custom_edge_with_my_edge.h"

void set_edge_selectedness_test() noexcept
{
  {
    auto g
      = create_empty_undirected_custom_and_selectable_edges_and_vertices_graph();
    const my_custom_edge edge{"Dex"};
    const auto ed = add_custom_and_selectable_edge(edge, true, g);
    assert(get_edge_selectedness(ed,g) == true);
    set_edge_selectedness(false, ed, g);
    assert(get_edge_selectedness(ed,g) == false);
  }
  set_edge_selectedness_demo();
  
}
