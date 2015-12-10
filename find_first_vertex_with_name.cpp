#include "find_first_vertex_with_name.h"

#include "find_first_vertex_with_name_demo.impl"

#include <cassert>

#include "create_named_vertices_k2_graph.h"
#include "get_vertex_name.h"

void find_first_vertex_with_name_test() noexcept
{
  {
    const auto g = create_named_vertices_k2_graph();
    const auto vd = find_first_vertex_with_name("from", g);
    assert(boost::out_degree(vd,g) == 1);
    assert(boost::in_degree(vd,g) == 1);
    assert(get_vertex_name(vd,g) == "from");
  }

  find_first_vertex_with_name_demo();
  std::cout << __func__ << ": OK" << '\n';
}

