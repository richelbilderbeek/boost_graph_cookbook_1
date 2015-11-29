#ifndef CREATE_ROUTER_NETWORK_H
#define CREATE_ROUTER_NETWORK_H

#include <boost/graph/adjacency_list.hpp>
#include <map>

struct router_network
{
  using graph = boost::adjacency_list<boost::listS,boost::vecS,boost::directedS>;
  using edge_descriptor = graph::edge_descriptor;
  using vertex_descriptor = graph::vertex_descriptor;
  router_network() : m_delay_map{}, m_graph{}, m_router_names{} {}
  std::map<edge_descriptor,int> m_delay_map;
  graph m_graph;
  std::map<vertex_descriptor,std::string> m_router_names;
};

router_network create_router_network() noexcept;

void test_create_router_network() noexcept;

#endif // CREATE_ROUTER_NETWORK_H
