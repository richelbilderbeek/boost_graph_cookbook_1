#include "is_named_vertices_isomorphic.h"

#include "is_named_vertices_isomorphic_demo.impl"

#include <cassert>
#include "create_path_graph.h"
#include "create_k2_graph.h"
#include "create_k3_graph.h"

void is_named_vertices_isomorphic_test() noexcept
{
  //Basic tests: K2 == path graph of 2 vertices
  {
    const auto g = create_path_graph(2);
    const auto h = create_k2_graph();
    assert(is_named_vertices_isomorphic(g,h));
  }
  //Basic tests: K3 != path graph of 3 vertices
  {
    const auto g = create_path_graph(3);
    const auto h = create_k3_graph();
    assert( is_named_vertices_isomorphic(g,g));
    assert( is_named_vertices_isomorphic(h,h));
    assert(!is_named_vertices_isomorphic(g,h));
  }
  is_named_vertices_isomorphic_demo();
  std::cout << __func__ << ": OK" << '\n';
}
