#ifndef GET_N_VERTICES_H
#define GET_N_VERTICES_H

#include <utility>
#include <boost/graph/adjacency_list.hpp>

///Get the number of vertices a graph has
template <class graph>
int get_n_vertices(const graph& g)
{
  const auto vertex_iters = boost::vertices(g);
  return std::distance(
    vertex_iters.first,
    vertex_iters.second
  );
}

#endif // GET_N_VERTICES_H
