#include "has_edge_between_vertices.h"

#include "has_edge_between_vertices_demo.impl"

#include <cassert>
#include <iostream>

#include "create_named_vertices_k2_graph.h"
#include "create_k2_graph.h"
#include "find_first_vertex_with_name.h"
#include "get_vertex_descriptors.h"
#include "create_path_graph.h"
#include "has_edge_between_vertices.h"

void has_edge_between_vertices_test() noexcept
{
  {
    const auto g = create_k2_graph();
    const auto vd_1 = *vertices(g).first;
    const auto vd_2 = *(++vertices(g).first);
    assert(!has_edge_between_vertices(vd_1, vd_1, g));
    assert( has_edge_between_vertices(vd_1, vd_2, g));
    assert( has_edge_between_vertices(vd_2, vd_1, g));
    assert(!has_edge_between_vertices(vd_2, vd_2, g));
  }
  {
    const auto g = create_named_vertices_k2_graph();
    const auto vd_1 = find_first_vertex_with_name("Me", g);
    const auto vd_2 = find_first_vertex_with_name("My computer", g);
    assert(has_edge_between_vertices(vd_1, vd_2, g));
  }
  //A three-vertex path graph has 4 edges (2 edges in 2 directions) to be detected
  {
    // A --- B --- C
    const int n_vertices{3};
    const auto g = create_path_graph(n_vertices);
    const auto vds = get_vertex_descriptors(g);
    assert(n_vertices == static_cast<int>(vds.size()));
    int cnt{0};
    for (int i=0; i!=n_vertices; ++i)
    {
      for (int j=0; j!=n_vertices; ++j)
      {
        if (has_edge_between_vertices(vds[i],vds[j], g)) ++cnt;
      }
    }
    assert(cnt == 4);
  }
  has_edge_between_vertices_demo();
  
}
