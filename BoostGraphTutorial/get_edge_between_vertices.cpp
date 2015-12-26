#include "get_edge_between_vertices.h"

#include "get_edge_between_vertices_demo.impl"

void get_edge_between_vertices_test() noexcept
{
  {
    auto g = create_k2_graph();
    const auto vd_1 = *vertices(g).first;
    const auto vd_2 = *(++vertices(g).first);
    assert(!has_edge_between_vertices(vd_1, vd_1, g));
    assert( has_edge_between_vertices(vd_1, vd_2, g));
    assert( has_edge_between_vertices(vd_2, vd_1, g));
    assert(!has_edge_between_vertices(vd_2, vd_2, g));
    const auto ed = get_edge_between_vertices(vd_1, vd_2, g);
    boost::remove_edge(ed, g);
    assert(boost::num_edges(g) == 0);
  }
  get_edge_between_vertices_demo();
  std::cout << __func__ << ": OK" << '\n';
}
