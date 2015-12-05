#ifndef GET_N_VERTICES_H
#define GET_N_VERTICES_H

#include <utility>
#include <boost/graph/adjacency_list.hpp>

///Get the number of vertices a graph has
template <class graph>
int get_n_vertices(const graph& g)
{
  return static_cast<int>(boost::num_vertices(g));
  /*
  using vertex_iterator
    = typename boost::graph_traits<graph>::vertex_iterator;
  using vertex_iterators
    = std::pair<vertex_iterator,vertex_iterator>;

  const vertex_iterators vertex_iters
    = boost::vertices(g);
  return std::distance(
    vertex_iters.first,
    vertex_iters.second
  );
  */
}

#endif // GET_N_VERTICES_H
