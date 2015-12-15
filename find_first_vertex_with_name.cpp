#include "find_first_vertex_with_name.h"

#include "find_first_vertex_with_name_demo.impl"

#include <cassert>

#include "create_named_vertices_k2_graph.h"
#include "get_vertex_name.h"

void find_first_vertex_with_name_test() noexcept
{
  {
    const auto g = create_named_vertices_k2_graph();
    const auto vd = find_first_vertex_with_name("A", g);
    assert(out_degree(vd,g) == 1); //_not_ boost::out_degree!
    assert(in_degree(vd,g) == 1); //_not_ boost::in_degree!
    assert(get_vertex_name(vd,g) == "A");
  }

  find_first_vertex_with_name_demo();
  std::cout << __func__ << ": OK" << '\n';
}

