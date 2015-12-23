#include "set_bundled_edge_my_edge.h"

#include "set_bundled_edge_my_edge_demo.impl"

#include <cassert>

#include "create_empty_undirected_bundled_edges_and_vertices_graph.h"
#include "add_bundled_edge.h"
#include "find_first_bundled_edge_with_my_edge.h"

void set_bundled_edge_my_edge_test() noexcept
{
  {
    auto g = create_empty_undirected_bundled_edges_and_vertices_graph();
    const my_bundled_edge old_name{"Dex"};
    add_bundled_edge(old_name, g);
    const auto vd = find_first_bundled_edge_with_my_edge(old_name, g);
    assert(get_bundled_edge_my_edge(vd, g) == old_name);
    const my_bundled_edge new_name{"Diggy"};
    set_bundled_edge_my_edge(new_name, vd, g);
    assert(get_bundled_edge_my_edge(vd, g) == new_name);
  }
  set_bundled_edge_my_edge_demo();
  std::cout << __func__ << ": OK" << '\n';
}
