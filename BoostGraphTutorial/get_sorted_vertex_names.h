#ifndef GET_SORTED_VERTEX_NAMES_H
#define GET_SORTED_VERTEX_NAMES_H

#include <string>
#include <vector>
#include "get_vertex_names.h"

template <class graph>
std::vector<std::string> get_sorted_vertex_names(
  const graph& g
) noexcept
{
  auto v = get_vertex_names(g);
  std::sort(std::begin(v),std::end(v));
  return v;
}

void get_sorted_vertex_names_test() noexcept;

#endif // GET_SORTED_VERTEX_NAMES_H
