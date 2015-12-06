#ifndef GET_N_EDGES_H
#define GET_N_EDGES_H

#include <utility>
#include <boost/graph/adjacency_list.hpp>

///Get the number of edges a graph has
template <class graph>
int get_n_edges(const graph& g)
{
  return static_cast<int>(boost::num_edges(g));
}

void get_n_edges_test() noexcept;

#endif // GET_N_EDGES_H
