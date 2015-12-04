#ifndef GET_N_EDGES_H
#define GET_N_EDGES_H

#include <utility>
#include <boost/graph/adjacency_list.hpp>

///Get the number of edges a graph has
template <class graph>
int get_n_edges(const graph& g)
{
  const auto edge_iters = boost::edges(g);
  return std::distance(edge_iters.first,edge_iters.second);
}

#endif // GET_N_EDGES_H
