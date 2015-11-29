#ifndef PRINT_VERTEX_NAMES_H
#define PRINT_VERTEX_NAMES_H

#include <iostream>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/properties.hpp>

//Here the vertex name map must be supplied
//From Siek, Jeremy G., Lie-Quan Lee, and Andrew Lumsdaine. Boost Graph Library: User Guide and Reference Manual, The. Pearson Education, 2001.
//Page 7
template <typename Graph, typename VertexNameMap>
void print_vertex_names(const Graph& g, const VertexNameMap& name_map)
{
  std::cout << "vertices(g) = { ";
  typedef typename boost::graph_traits<Graph>::vertex_iterator iter_t;
  for (std::pair<iter_t,iter_t> p = vertices(g); p.first != p.second; ++p.first) {
    print_vertex_name(*p.first, name_map); std::cout << ' ';
  }
  std::cout << "}" << std::endl;
}

template <typename Graph>
void print_vertex_names(const Graph& g)
{
  using name_map_t = typename boost::property_map<Graph,boost::vertex_name_t>::type;
  const name_map_t name_map{boost::get(boost::vertex_name,g)};
  print_vertex_names(g,name_map);
}

void test_print_vertex_names() noexcept;

#endif // PRINT_VERTEX_NAMES_H
