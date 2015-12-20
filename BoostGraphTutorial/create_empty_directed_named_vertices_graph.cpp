#include "create_empty_directed_named_vertices_graph.h"

#include "create_empty_directed_named_vertices_graph.h"

#include "create_empty_directed_named_vertices_graph_demo.impl"

#include <cassert>
#include <iostream>



#include "get_edge_iterators.h"
#include "get_vertex_iterators.h"
#include "get_edge_descriptors.h"
#include "get_vertex_descriptors.h"
#include "add_edge.h"
#include "add_named_vertex.h"

void create_empty_directed_named_vertices_graph_test() noexcept
{
  //Basic testing
  {
    auto g = create_empty_directed_named_vertices_graph();
    const auto vip = get_vertex_iterators(g);
    assert(vip.first == vip.second);
    const auto vds = get_vertex_descriptors(g);
    assert(vds.empty());
    const auto eip = get_edge_iterators(g);
    assert(eip.first == eip.second);
    const auto eds = get_edge_descriptors(g);
    assert(eds.empty());
    assert(boost::num_edges(g) == 0);
    assert(boost::num_vertices(g) == 0);
    add_named_vertex("A",g);
    assert(boost::num_edges(g) == 0);
    assert(boost::num_vertices(g) == 1);
    add_edge(g);
    assert(boost::num_edges(g) == 1);
    assert(boost::num_vertices(g) == 3);
  }
  //Basic testing on different type graph
  {
    auto g = create_empty_directed_named_vertices_graph<int>();
    const auto vip = get_vertex_iterators(g);
    assert(vip.first == vip.second);
    const auto vds = get_vertex_descriptors(g);
    assert(vds.empty());
    const auto eip = get_edge_iterators(g);
    assert(eip.first == eip.second);
    const auto eds = get_edge_descriptors(g);
    assert(eds.empty());
    assert(boost::num_edges(g) == 0);
    assert(boost::num_vertices(g) == 0);
    add_named_vertex(42,g);
    assert(boost::num_edges(g) == 0);
    assert(boost::num_vertices(g) == 1);
    add_edge(g);
    assert(boost::num_edges(g) == 1);
    assert(boost::num_vertices(g) == 3);
  }
  create_empty_named_directed_vertices_graph_demo();
  std::cout << __func__ << ": OK" << '\n';
}
