#include "is_custom_vertices_isomorphic.h"

#include "is_custom_vertices_isomorphic_demo.impl"

#include <cassert>
#include "create_path_graph.h"
#include "create_k2_graph.h"
#include "create_k3_graph.h"
#include "create_custom_vertices_path_graph.h"

void is_custom_vertices_isomorphic_test() noexcept
{
  {
    const auto g = create_custom_vertices_path_graph(
      {
        my_custom_vertex("Alpha"),
        my_custom_vertex("Beta"),
        my_custom_vertex("Gamma")
      }
    );
    const auto h = create_custom_vertices_path_graph(
      {
        my_custom_vertex("Alpha"),
        my_custom_vertex("Beta"),
        my_custom_vertex("Gamma")
      }
    );
    assert( is_custom_vertices_isomorphic(g,h));
  }
  {
    const auto g = create_custom_vertices_path_graph(
      {
        my_custom_vertex("Alpha"),
        my_custom_vertex("Beta"),
        my_custom_vertex("Gamma")
      }
    );
    const auto h = create_custom_vertices_path_graph(
      {
        my_custom_vertex("Gamma"),
        my_custom_vertex("Beta"),
        my_custom_vertex("Alpha")
      }
    );
    assert( is_custom_vertices_isomorphic(g,h));
  }
  {
    const auto g = create_custom_vertices_path_graph(
      {
        my_custom_vertex("Alpha"),
        my_custom_vertex("Beta"),
        my_custom_vertex("Gamma")
      }
    );
    const auto h = create_custom_vertices_path_graph(
      {
        my_custom_vertex("Alpha"),
        my_custom_vertex("Gamma"),
        my_custom_vertex("Beta")
      }
    );
    assert( is_custom_vertices_isomorphic(g,g));
    assert(!is_custom_vertices_isomorphic(g,h));
  }
  is_custom_vertices_isomorphic_demo();
  
}




