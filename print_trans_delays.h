#ifndef PRINT_TRANS_DELAYS_H
#define PRINT_TRANS_DELAYS_H

#include <iostream>
#include <boost/graph/graph_traits.hpp>

//From Siek, Jeremy G., Lie-Quan Lee, and Andrew Lumsdaine. Boost Graph Library: User Guide and Reference Manual, The. Pearson Education, 2001.
//Page 8
template <typename Graph, typename TransDelayMap, typename VertexNameMap>
void print_trans_delays(const Graph& g, TransDelayMap trans_delay_map,
  VertexNameMap name_map)
{
  typename boost::graph_traits<Graph>::edge_iterator first, last;
  for (tie(first,last) = edges(g); first != last; ++first) {
    print_trans_delay(*first, g, trans_delay_map, name_map);
    std::cout << '\n';
  }
}

void test_print_trans_delays() noexcept;

#endif // PRINT_TRANS_DELAYS_H
