#ifndef GET_VERTEX_NAMES_H
#define GET_VERTEX_NAMES_H

#include "get_vertex_names.impl"

//TODO: generalize to return any type
template <typename graph>
std::vector<std::string> get_vertex_names_DOESNOTWORK(const graph& g)
{
  using vertex_iterator
    = typename boost::graph_traits<graph>::vertex_iterator;
  using vertex_iterators
    = std::pair<vertex_iterator,vertex_iterator>;
  using name_map_t
    = typename boost::property_map<graph,boost::vertex_name_t>::type;

  std::vector<std::string> v;

  const name_map_t name_map = get(boost::vertex_name,g);

  for (vertex_iterators p = vertices(g);
    p.first != p.second;
    ++p.first)
  {
    v.emplace_back(get(name_map, *p.first));
  }
  return v;
}

void get_vertex_names_test() noexcept;

#endif // GET_VERTEX_NAMES_H
