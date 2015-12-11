#ifndef PRINT_TRANS_DELAY_H
#define PRINT_TRANS_DELAY_H

#include <iostream>
#include <boost/graph/graph_traits.hpp>

//From Siek, Jeremy G., Lie-Quan Lee, and Andrew Lumsdaine. Boost Graph Library: User Guide and Reference Manual, The. Pearson Education, 2001.
//Page 6
template <typename Graph, typename TransDelayMap, typename VertexNameMap>
void print_trans_delay(
  typename boost::graph_traits<Graph>::edge_descriptor e,
  const Graph& g,
  const TransDelayMap& delay_map,
  const VertexNameMap& name_map
)
{
  std::cout
    << "trans_delay("
    << std::get(name_map,std::source(e,g)) << ","
    << std::get(name_map,std::target(e,g)) << ") = "
    << std::get(delay_map,e)
  ;

  std::cout
    << "trans_delay("
    << get(name_map,std::source(e,g)) << ","
    << get(name_map,std::target(e,g)) << ") = "
    << get(delay_map,e)
  ;
}

void print_trans_delay_test() noexcept;

#endif // PRINT_TRANS_DELAY_H
