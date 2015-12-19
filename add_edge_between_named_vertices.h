#ifndef ADD_EDGE_BETWEEN_NAMED_VERTICES_H
#define ADD_EDGE_BETWEEN_NAMED_VERTICES_H

#include <cassert>
#include <string>
#include <boost/graph/adjacency_list.hpp>
#include "has_vertex_with_name.h"
#include "find_first_vertex_with_name.h"

template <class graph>
void add_edge_between_named_vertices(
  const std::string& vertex_name_1,
  const std::string& vertex_name_2,
  graph& g
) noexcept
{
  assert(has_vertex_with_name(vertex_name_1, g));
  assert(has_vertex_with_name(vertex_name_2, g));
  const auto vd_1 = find_first_vertex_with_name(vertex_name_1, g);
  const auto vd_2 = find_first_vertex_with_name(vertex_name_2, g);
  const auto aer = boost::add_edge(vd_1, vd_2, g);
  assert(aer.second);

}

#endif // ADD_EDGE_BETWEEN_NAMED_VERTICES_H
