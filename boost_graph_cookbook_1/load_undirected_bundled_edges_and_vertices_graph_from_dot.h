#ifndef LOAD_UNDIRECTED_BUNDLED_EDGES_AND_VERTICES_GRAPH_FROM_DOT_H
#define LOAD_UNDIRECTED_BUNDLED_EDGES_AND_VERTICES_GRAPH_FROM_DOT_H

#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
#include "create_empty_undirected_bundled_edges_and_vertices_graph.h"

#include "is_regular_file.h"

template <class graph>
graph load_undirected_bundled_edges_and_vertices_graph_from_dot(
  const std::string& dot_filename
)
{
  if (!is_regular_file(dot_filename))
  {
    std::stringstream msg;
    msg << __func__ << ": file '"
      << dot_filename << "' not found"
    ;
    throw std::invalid_argument(msg.str());
  }
  std::ifstream f(dot_filename);
  graph g;

  boost::dynamic_properties dp(boost::ignore_other_properties);
  dp.property("label",get(&my_bundled_vertex::m_name, g));
  dp.property("comment", get(&my_bundled_vertex::m_description, g));
  dp.property("width", get(&my_bundled_vertex::m_x, g));
  dp.property("height", get(&my_bundled_vertex::m_y, g));
  dp.property("edge_id",get(&my_bundled_edge::m_name, g));
  dp.property("label",get(&my_bundled_edge::m_name, g));
  dp.property("comment", get(&my_bundled_edge::m_description, g));
  dp.property("width", get(&my_bundled_edge::m_width, g));
  dp.property("height", get(&my_bundled_edge::m_height, g));
  boost::read_graphviz(f,g,dp);

  //Decode vertices
  {
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i = vip.first; i!=j; ++i)
    {
      g[*i].m_name = graphviz_decode(g[*i].m_name);
      g[*i].m_description = graphviz_decode(g[*i].m_description);
    }
  }

  //Decode edges
  {
    const auto eip = edges(g);
    const auto j = eip.second;
    for (auto i = eip.first; i!=j; ++i)
    {
      g[*i].m_name = graphviz_decode(g[*i].m_name);
      g[*i].m_description = graphviz_decode(g[*i].m_description);
    }
  }

  return g;
}

/*
template <class graph = decltype(create_empty_undirected_bundled_edges_and_vertices_graph())>
graph load_undirected_bundled_edges_and_vertices_graph_from_dot(
  const std::string& dot_filename
);
*/

#else
#error(Do not include this file when BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ is defined)
#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ

#endif // LOAD_UNDIRECTED_BUNDLED_EDGES_AND_VERTICES_GRAPH_FROM_DOT_H
