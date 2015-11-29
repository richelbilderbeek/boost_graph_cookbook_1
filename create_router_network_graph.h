#ifndef CREATE_ROUTER_NETWORK_GRAPH_H
#define CREATE_ROUTER_NETWORK_GRAPH_H

#include <boost/graph/adjacency_list.hpp>
#include <map>


boost::adjacency_list<
  boost::listS, //store out-edges are std::list
  boost::listS, //store vertices in std::list
  boost::directedS, //it is a directed graph
  boost::property<boost::vertex_name_t,std::string>, //vertex properties
  boost::property<boost::edge_weight_t,double> //edge properties
>
create_router_network_graph() noexcept;

void test_create_router_network_graph() noexcept;


#endif // CREATE_ROUTER_NETWORK_GRAPH_H
