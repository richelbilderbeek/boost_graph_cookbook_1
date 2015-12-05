#ifndef GET_EDGE_NAMES
#define GET_EDGE_NAMES

#include <string>
#include <vector>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/properties.hpp>

//TODO: generalize to return any type
template <typename graph>
std::vector<std::string> get_edge_names(const graph& g)
{
  using edge_iterator
    = typename boost::graph_traits<graph>::edge_iterator;
  using edge_iterators
    = std::pair<edge_iterator,edge_iterator>;

  std::vector<std::string> v;

  //TODO: remove auto
  const auto edge_name_map = get(boost::edge_name,g);

  for (edge_iterators p = edges(g);
    p.first != p.second;
    ++p.first)
  {
    v.emplace_back(get(edge_name_map, *p.first));
  }
  return v;
}

void get_edge_names_test() noexcept;


#endif // GET_EDGE_NAMES

