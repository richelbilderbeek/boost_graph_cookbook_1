#ifndef CREATE_ROUTER_NETWORK_H
#define CREATE_ROUTER_NETWORK_H

#include <boost/graph/adjacency_list.hpp>

boost::adjacency_list<
  boost::listS,    // Store out-edges of each vertex in a std::list
  boost::vecS,     // Store vertices in a std::vector
  boost::directedS // The graph is directed
>
create_router_network() noexcept;

void test_create_router_network() noexcept;

#endif // CREATE_ROUTER_NETWORK_H
