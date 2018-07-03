#ifndef GET_SORTED_VERTEX_TEXTS_H
#define GET_SORTED_VERTEX_TEXTS_H

#include "get_vertex_texts.h"
#include <string>
#include <vector>

template <class graph>
std::vector<std::string> get_sorted_vertex_texts(const graph& g) noexcept
{
  auto v = get_vertex_texts(g);
  std::sort(std::begin(v), std::end(v));
  return v;
}

#endif // GET_SORTED_VERTEX_TEXTS_H
