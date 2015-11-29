#ifndef IS_SELF_LOOP_H
#define IS_SELF_LOOP_H

#include <boost/graph/graph_traits.hpp>

//From Siek, Jeremy G., Lie-Quan Lee, and Andrew Lumsdaine. Boost Graph Library: User Guide and Reference Manual, The. Pearson Education, 2001.
//Page 6
template <typename Graph>
bool is_self_loop(typename boost::graph_traits<Graph>::edge_descriptor e, const Graph& g)
{
  typename boost::graph_traits<Graph>::vertex_descriptor u, v;
  u = source(e,g);
  v = target(e,g);
  return u == v;
}

void test_is_self_loop() noexcept;

#endif // IS_SELF_LOOP_H
