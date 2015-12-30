#ifndef IS_NAMED_VERTICES_ISOMORPHIC_H
#define IS_NAMED_VERTICES_ISOMORPHIC_H

#include "is_named_vertices_isomorphic.impl"

#include <boost/graph/adjacency_list.hpp>

/*
template <typename Graph>
std::string discrete_vertex_invariant(
  const typename boost::graph_traits<Graph>::vertex_descriptor& vd,
  const Graph &g
)
{
  const auto name_map = get(boost::vertex_name,g);
  return name_map[vd];
}

template <typename Graph>
class discrete_vertex_invariant_functor
{
    using vertex_t = typename boost::graph_traits<Graph>::vertex_descriptor;
    const Graph& m_graph;
public:
    using result_type = std::string;
    using argument_type = vertex_t;
    discrete_vertex_invariant_functor(const Graph &g) : m_graph(g) {}
    result_type operator()(const vertex_t& vd) const
    {
        return discrete_vertex_invariant(vd,m_graph);
    }
    result_type max() const
    {
        return "";
    }
};

//helper function to help with argument deduction
template <typename Graph>
discrete_vertex_invariant_functor<Graph> make_discrete_vertex_invariant(
  const Graph &g
)
{
  return discrete_vertex_invariant_functor<Graph>(g);
}

template <typename graph1, typename graph2>
bool is_named_vertices_isomorphic_correct(
  const graph1& g,
  const graph2& h
) noexcept
{
  auto ref_index_map = get(boost::vertex_index, g);
  using vd = typename boost::graph_traits<graph1>::vertex_descriptor;
  std::vector<vd> iso(boost::num_vertices(g));

#ifdef USE_A
  return boost::isomorphism(
    g,
    h,
    isomorphism_map(
      make_iterator_property_map(iso.begin(), ref_index_map, iso[0])
    ).vertex_invariant1(make_discrete_vertex_invariant(g))
     .vertex_invariant2(make_discrete_vertex_invariant(h))
  );
  #else
  return boost::isomorphism(g,h,
    boost::isomorphism_map(
      make_iterator_property_map(iso.begin(), ref_index_map, iso[0])
    )
  );
  #endif
}
*/

void is_named_vertices_isomorphic_test() noexcept;

#endif // IS_NAMED_VERTICES_ISOMORPHIC_H
