#include "create_router_network.h"

#include <iostream>

#include "build_router_network.h"
#include "create_empty_graph.h"
#include "get_n_edges.h"
#include "get_n_vertices.h"

router_network create_router_network() noexcept
{
  router_network r;
  build_router_network(r.m_graph,r.m_router_names,r.m_delay_map);
  return r;
}

void test_create_router_network() noexcept
{
  const auto r = create_router_network();
  assert(get_n_edges(r.m_graph) == 7);
  assert(get_n_edges(r.m_graph) == static_cast<int>(r.m_delay_map.size()));
  assert(get_n_vertices(r.m_graph) == 5);
  assert(get_n_vertices(r.m_graph) == static_cast<int>(r.m_router_names.size()));

  std::cout << __func__ << ": OK" << '\n';
}


