#include "set_custom_vertex_my_vertex.h"

#include "set_custom_vertex_my_vertex_demo.impl"

#include <cassert>

#include "create_empty_undirected_custom_vertices_graph.h"
#include "add_custom_vertex.h"
#include "find_first_custom_vertex_with_my_vertex.h"

void set_custom_vertex_my_vertex_test() noexcept
{
  {
    auto g = create_empty_undirected_custom_vertices_graph();
    const my_vertex old_name{"Dex"};
    add_custom_vertex(old_name, g);
    const auto vd = find_first_custom_vertex_with_my_vertex(old_name, g);
    assert(get_custom_vertex_my_vertex(vd, g) == old_name);
    const my_vertex new_name{"Diggy"};
    set_custom_vertex_my_vertex(new_name, vd, g);
    assert(get_custom_vertex_my_vertex(vd, g) == new_name);
  }
  set_custom_vertex_my_vertex_demo();
  std::cout << __func__ << ": OK" << '\n';
}
