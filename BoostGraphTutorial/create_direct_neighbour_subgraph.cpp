#include "create_direct_neighbour_subgraph.h"
#include "create_direct_neighbour_subgraph_demo.impl"

#include "create_k2_graph.h"
#include "create_k3_graph.h"
#include "create_petersen_graph.h"

void create_direct_neighbour_subgraph_test() noexcept
{
  //K2
  {
    const auto g = create_k2_graph();
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i=vip.first; i!=j; ++i) {
      const auto h = create_direct_neighbour_subgraph(
        *i,g
      );
      assert(boost::num_vertices(h) == 2);
      assert(boost::num_edges(h) == 1);

    }
  }
  //K3
  {
    const auto g = create_k3_graph();
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i=vip.first; i!=j; ++i) {
      const auto h = create_direct_neighbour_subgraph(
        *i,g
      );
      assert(boost::num_vertices(h) == 3);
      assert(boost::num_edges(h) == 3);

    }
  }
  //Petersen Graph
  {
    const auto g = create_petersen_graph();
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i = vip.first; i!=j; ++i) {
      const auto h = create_direct_neighbour_subgraph(
        *i,g
      );
      assert(boost::num_vertices(h) == 4);
      assert(boost::num_edges(h) == 3);
    }
  }
  create_direct_neighbour_subgraph_demo();
  std::cout << __func__ << ": OK" << '\n';
}
