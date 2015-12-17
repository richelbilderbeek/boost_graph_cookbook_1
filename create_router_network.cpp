#include "create_router_network.h"

#include <iostream>

#include "build_router_network.h"



router_network create_router_network() noexcept
{
  router_network r;
  build_router_network(r.m_graph,r.m_router_names,r.m_delay_map);
  return r;
}

void create_router_network_test() noexcept
{
  const auto r = create_router_network();
  assert(boost::num_edges(r.m_graph) == 7);
  assert(boost::num_edges(r.m_graph) == r.m_delay_map.size());
  assert(boost::num_vertices(r.m_graph) == 5);
  assert(boost::num_vertices(r.m_graph) == r.m_router_names.size());

  std::cout << __func__ << ": OK" << '\n';
}


