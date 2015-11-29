#ifndef PRINT_VERTEX_NAME_H
#define PRINT_VERTEX_NAME_H

#include <iostream>
//#include <boost/graph/graph_traits.hpp>

//From Siek, Jeremy G., Lie-Quan Lee, and Andrew Lumsdaine. Boost Graph Library: User Guide and Reference Manual, The. Pearson Education, 2001.
//Page 6
template <typename VertexDescriptor, typename VertexNameMap>
void print_vertex_name(VertexDescriptor v, VertexNameMap name_map)
{
  std::cout << get(name_map, v);
}

void test_print_vertex_name() noexcept;

#endif // PRINT_VERTEX_NAME_H
