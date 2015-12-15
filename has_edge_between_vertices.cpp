#include "has_edge_between_vertices.h"

#include "create_named_vertices_k2_graph.h"
#include "find_first_vertex_with_name.h"

void has_edge_between_vertices_test() noexcept
{
  {
    const auto g = create_named_vertices_k2_graph();
    const auto vd_1 = find_first_vertex_with_name("A", g);
    const auto vd_2 = find_first_vertex_with_name("B", g);
    assert(has_edge_between_vertices(vd_1, vd_2, g));
  }
  //has_edge_between_vertices_test_demo();
  std::cout << __func__ << ": OK" << '\n';
}
