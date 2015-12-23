#ifndef GET_SORTED_NAMED_VERTEX_MY_VERTEXES_H
#define GET_SORTED_NAMED_VERTEX_MY_VERTEXES_H

#include "get_vertex_names.h"

///Collect all the vertex names and
///sort these before returning
//TODO: generalize to return any type
template <typename graph>
std::vector<std::string>
get_sorted_vertex_names(const graph& g) noexcept
{
  auto v = get_vertex_names(g);
  std::sort(std::begin(v),std::end(v));
  return v;
}

#endif // GET_SORTED_NAMED_VERTEX_MY_VERTEXES_H
