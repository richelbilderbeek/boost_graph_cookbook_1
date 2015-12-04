#ifndef SET_VERTEX_NAMES_H
#define SET_VERTEX_NAMES_H


#include <string>
#include <vector>

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/properties.hpp>

//TODO: generalize 'names'
template <typename graph>
void set_vertex_names(
  graph& g,
  const std::vector<std::string>& names
)
{
  using vertex_iterator
    = typename boost::graph_traits<graph>::vertex_iterator;
  using vertex_iterators
    = std::pair<vertex_iterator,vertex_iterator>;

  const auto name_map = get(boost::vertex_name,g);

  auto names_begin = std::begin(names);
  const auto names_end = std::end(names);
  for (vertex_iterators vi = vertices(g);
    vi.first != vi.second;
    ++vi.first, ++names_begin)
  {
    assert(names_begin != names_end);
    put(name_map, *vi.first,*names_begin);
  }
}


#endif // SET_VERTEX_NAMES_H
