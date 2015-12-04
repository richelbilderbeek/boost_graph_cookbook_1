#ifndef PRINT_TRANS_DELAYS_H
#define PRINT_TRANS_DELAYS_H

#include <iostream>
#include <boost/graph/graph_traits.hpp>

#include "print_trans_delay.h"

//From Siek, Jeremy G., Lie-Quan Lee, and Andrew Lumsdaine. Boost Graph Library: User Guide and Reference Manual, The. Pearson Education, 2001.
//Page 8
template <typename Graph, typename TransDelayMap, typename VertexNameMap>
void print_trans_delays(
  const Graph& g,
  const TransDelayMap& trans_delay_map,
  const VertexNameMap& name_map
)
{
  typename boost::graph_traits<Graph>::edge_iterator first, last;
  for (tie(first,last) = edges(g); first != last; ++first) {
    print_trans_delay(*first, g, trans_delay_map, name_map);
    std::cout << '\n';
  }
}

void print_trans_delays_test() noexcept;

#endif // PRINT_TRANS_DELAYS_H
