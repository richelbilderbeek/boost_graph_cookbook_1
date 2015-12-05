#ifndef ADD_VERTEX
#define ADD_VERTEX

#include <boost/graph/adjacency_list.hpp>

template <typename graph, typename vertex>
void add_vertex(graph& g)
{
  boost::add_vertex(g);
}

void add_vertex_test() noexcept;

#endif // ADD_VERTEX

