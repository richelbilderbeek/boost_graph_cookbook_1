#ifndef IS_SELF_LOOP_H
#define IS_SELF_LOOP_H

#include <boost/graph/graph_traits.hpp>

//Adapted from Siek, Jeremy G., Lie-Quan Lee, and Andrew Lumsdaine. Boost Graph Library: User Guide and Reference Manual, The. Pearson Education, 2001.
//Page 6
template <typename graph>
bool is_self_loop(
  typename boost::graph_traits<graph>::edge_descriptor e,
  const graph& g
) noexcept {
  return source(e,g) == target(e,g);
}

void is_self_loop_test() noexcept;

#endif // IS_SELF_LOOP_H
