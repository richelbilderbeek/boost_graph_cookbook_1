#include "load_undirected_graph_from_dot.h"



#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graphviz.hpp>

#include "create_empty_undirected_graph.h"
#include "is_regular_file.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS
>
load_undirected_graph_from_dot(
  const std::string& dot_filename
)
{
  assert(is_regular_file(dot_filename));
  std::ifstream f(dot_filename.c_str());
  auto g = create_empty_undirected_graph();
  boost::dynamic_properties p;
  //boost::dynamic_properties p(boost::ignore_other_properties);
  boost::read_graphviz(f,g,p);
  return g;
}

#include "create_k2_graph.h"
#include "save_graph_to_dot.h"

#include <iostream>

void load_undirected_graph_from_dot_test() noexcept
{
  const auto g = create_k2_graph();
  const std::string filename{"load_undirected_graph_from_dot_test_k2.dot"};
  save_graph_to_dot(g, filename);
  const auto h = load_undirected_graph_from_dot(filename);
  assert(boost::num_edges(g) == boost::num_edges(h));
  assert(boost::num_vertices(g) == boost::num_vertices(h));
  assert(!"Green");
  //load_undirected_graph_from_dot_demo();
  std::cout << __func__ << ": OK" << '\n';
}
