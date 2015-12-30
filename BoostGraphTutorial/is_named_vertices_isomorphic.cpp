#include "is_named_vertices_isomorphic.h"

#include "is_named_vertices_isomorphic_demo.impl"

#include <cassert>
#include "create_path_graph.h"
#include "create_k2_graph.h"
#include "create_k3_graph.h"
#include "create_named_vertices_path_graph.h"

void is_named_vertices_isomorphic_test() noexcept
{
  {
    const auto g = create_named_vertices_path_graph(
      { "Alpha", "Beta", "Gamma" }
    );
    const auto h = create_named_vertices_path_graph(
      { "Alpha", "Beta", "Gamma" }
    );
    assert( is_named_vertices_isomorphic(g,h));
  }
  {
    const auto g = create_named_vertices_path_graph(
      { "Alpha", "Beta", "Gamma" }
    );
    const auto h = create_named_vertices_path_graph(
      { "Gamma", "Beta", "Alpha" }
    );
    assert( is_named_vertices_isomorphic(g,h));
  }
  {
    const auto g = create_named_vertices_path_graph(
      { "Alpha", "Beta", "Gamma" }
    );
    const auto h = create_named_vertices_path_graph(
      { "Alpha", "Gamma", "Beta" }
    );
    assert( is_named_vertices_isomorphic(g,g));
    assert(!is_named_vertices_isomorphic(g,h));
  }
  is_named_vertices_isomorphic_demo();
  std::cout << __func__ << ": OK" << '\n';
}




