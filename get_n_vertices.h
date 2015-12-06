#ifndef GET_N_VERTICES_H
#define GET_N_VERTICES_H

#include <utility>
#include <boost/graph/adjacency_list.hpp>

///Get the number of vertices a graph has
template <class graph>
int get_n_vertices(const graph& g)
{
  return static_cast<int>(boost::num_vertices(g));
}

void get_n_vertices_test() noexcept;

#endif // GET_N_VERTICES_H
