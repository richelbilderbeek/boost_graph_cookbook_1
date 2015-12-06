#ifndef PRINT_VERTEX_NAME_H
#define PRINT_VERTEX_NAME_H

#include <iostream>

//From Siek, Jeremy G., Lie-Quan Lee, and Andrew Lumsdaine. Boost Graph Library: User Guide and Reference Manual, The. Pearson Education, 2001.
//Page 6
template <typename VertexDescriptor, typename VertexNameMap>
void print_vertex_name(
  const VertexDescriptor& v,
  const VertexNameMap& name_map)
{
  std::cout << get(name_map, v) << std::endl;
}

void print_vertex_name_test() noexcept;

#endif // PRINT_VERTEX_NAME_H
