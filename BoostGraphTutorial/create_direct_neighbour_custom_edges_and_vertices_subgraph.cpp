#include "create_direct_neighbour_custom_edges_and_vertices_subgraph.h"
#include "create_direct_neighbour_custom_edges_and_vertices_subgraph_demo.impl"

#include <cassert>
#include <iostream>

#include "create_custom_edges_and_vertices_k2_graph.h"
#include "create_custom_edges_and_vertices_k3_graph.h"
#include "create_custom_edges_and_vertices_path_graph.h"
#include "create_custom_edges_and_vertices_petersen_graph.h"
#include "get_my_custom_vertex.h"
#include "get_my_custom_vertexes.h"
#include "get_my_custom_edges.h"

void create_direct_neighbour_custom_edges_and_vertices_subgraph_test() noexcept
{
  //K2
  {
    const auto g = create_custom_edges_and_vertices_k2_graph();
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i=vip.first; i!=j; ++i) {
      const auto h = create_direct_neighbour_custom_edges_and_vertices_subgraph(
        *i,g
      );
      assert(boost::num_vertices(h) == 2);
      assert(boost::num_edges(h) == 1);
      const auto v = get_my_custom_vertexes(h);
      std::set<my_custom_vertex> vertexes(std::begin(v),std::end(v));
      const my_custom_vertex a("A","source",0.0,0.0);
      const my_custom_vertex b("B","target",3.14,3.14);
      assert(vertexes.count(a) == 1);
      assert(vertexes.count(b) == 1);
    }
  }
  //K3
  {
    const auto g = create_custom_edges_and_vertices_k3_graph();
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i=vip.first; i!=j; ++i) {
      const auto h = create_direct_neighbour_custom_edges_and_vertices_subgraph(
        *i,g
      );
      assert(boost::num_vertices(h) == 3);
      assert(boost::num_edges(h) == 3);
      const auto v = get_my_custom_vertexes(h);
      std::set<my_custom_vertex> vertexes(std::begin(v),std::end(v));
      const auto e = get_my_custom_edges(h);
      std::set<my_custom_edge> edges(std::begin(e),std::end(e));
      const my_custom_vertex va("top","source",0.0,0.0);
      const my_custom_vertex vb("right","target",3.14,0);
      const my_custom_vertex vc("left","target",0,3.14);
      const my_custom_edge ea("AB","first",0.0,0.0);
      const my_custom_edge eb("BC","second",3.14,3.14);
      const my_custom_edge ec("CA","third",3.14,3.14);
      assert(vertexes.count(va) == 1);
      assert(vertexes.count(vb) == 1);
      assert(vertexes.count(vc) == 1);
      assert(edges.count(ea) == 1);
      assert(edges.count(eb) == 1);
      assert(edges.count(ec) == 1);
    }
  }
  //Path graph
  {
    const my_custom_vertex a("A","first",1.1,2.2);
    const my_custom_vertex b("B","second",3.3,4.4);
    const my_custom_vertex c("C","third",5.5,6.6);
    const my_custom_edge d("1","first",7.7,8.8);
    const my_custom_edge e("2","second",9.9,0.0);
    std::vector<my_custom_edge> my_edges = {d,e};
    std::vector<my_custom_vertex> my_vertices = {a,b,c};
    const auto g = create_custom_edges_and_vertices_path_graph(my_edges, my_vertices);
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i=vip.first; i!=j; ++i) {

      const auto h = create_direct_neighbour_custom_edges_and_vertices_subgraph(
        *i,g
      );

      if (get_my_custom_vertex(*i, g) == a) {
        assert(boost::num_vertices(h) == 2);
        assert(boost::num_edges(h) == 1);
        const auto v = get_my_custom_vertexes(h);
        std::set<my_custom_vertex> vertexes(std::begin(v),std::end(v));
        assert(vertexes.count(a) == 1);
        assert(vertexes.count(b) == 1);
      }
      if (get_my_custom_vertex(*i, g) == b) {
        assert(boost::num_vertices(h) == 3);
        assert(boost::num_edges(h) == 2);
        const auto v = get_my_custom_vertexes(h);
        std::set<my_custom_vertex> vertexes(std::begin(v),std::end(v));
        assert(vertexes.count(a) == 1);
        assert(vertexes.count(b) == 1);
        assert(vertexes.count(c) == 1);
      }
      if (get_my_custom_vertex(*i, g) == c) {
        assert(boost::num_vertices(h) == 2);
        assert(boost::num_edges(h) == 1);
        const auto v = get_my_custom_vertexes(h);
        std::set<my_custom_vertex> vertexes(std::begin(v),std::end(v));
        assert(vertexes.count(b) == 1);
        assert(vertexes.count(c) == 1);
      }
    }
  }

  create_direct_neighbour_custom_edges_and_vertices_subgraph_demo();
}
