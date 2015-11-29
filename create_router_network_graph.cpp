#include "create_router_network_graph.h"

#include <iostream>
#include <string>

#include "get_n_edges.h"
#include "get_n_vertices.h"
#include "print_vertex_names.h"

boost::adjacency_list<
  boost::listS, //store out-edges are std::list
  boost::listS, //store vertices in std::list
  boost::directedS, //it is a directed graph
  boost::property<boost::vertex_name_t,std::string>, //vertex properties
  boost::property<boost::edge_weight_t,double> //edge properties
>
create_router_network_graph() noexcept
{
  using graph = boost::adjacency_list<
    boost::listS, //store out-edges are std::list
    boost::listS, //store vertices in std::list
    boost::directedS, //it is a directed graph
    boost::property<boost::vertex_name_t,std::string>, //vertex properties
    boost::property<boost::edge_weight_t,double> //edge properties
  >;
  using my_vertex_descriptor = typename boost::graph_traits<graph>::vertex_descriptor;
  using name_map_t = boost::property_map<graph,boost::vertex_name_t>::type;
  using edge_weight_t = boost::property_map<graph,boost::edge_weight_t>::type;


  graph g;

  name_map_t name_map{boost::get(boost::vertex_name,g)};
  edge_weight_t delay_map{boost::get(boost::edge_weight,g)};

  //9a
  const my_vertex_descriptor va = add_vertex(g); name_map[va] = "a";
  const my_vertex_descriptor vb = add_vertex(g); name_map[vb] = "b";
  const my_vertex_descriptor vc = add_vertex(g); name_map[vc] = "c";
  const my_vertex_descriptor vd = add_vertex(g); name_map[vd] = "d";
  const my_vertex_descriptor ve = add_vertex(g); name_map[ve] = "e";

  //9b
  using my_edge_descriptor = typename boost::graph_traits<graph>::edge_descriptor;

  //The boolean: if it has been successfully inserted
  using my_pair = std::pair<my_edge_descriptor,bool>;

  const my_pair ea = add_edge(va, vb, g); delay_map[ea.first] = 1.2; assert(ea.second);
  const my_pair eb = add_edge(va, vd, g); delay_map[eb.first] = 4.5; assert(eb.second);
  const my_pair ec = add_edge(vb, vd, g); delay_map[ec.first] = 1.8; assert(ec.second);
  const my_pair ed = add_edge(vc, va, g); delay_map[ed.first] = 2.6; assert(ed.second);
  const my_pair ee = add_edge(vc, ve, g); delay_map[ee.first] = 5.2; assert(ee.second);
  const my_pair ef = add_edge(vd, vc, g); delay_map[ef.first] = 0.4; assert(ef.second);
  const my_pair eg = add_edge(vd, ve, g); delay_map[eg.first] = 3.3; assert(eg.second);


  for (auto i = boost::vertices(g); i.first != i.second; ++i.first) {
    std::cout << name_map[*i.first] << std::endl;
  }
  assert(!"This must be put in a function");
  //Does not workname_map
  //for (const auto& i: name_map) {
  //  std::cout << i << std::endl;
  //}

  //Does not work
  //for (auto i = std::begin(name_map); i.first != i.end(); ++i) {
  //  std::cout << i.first << std::endl;
  //}
  //print_vertex_names(g);
  return g;
}


void test_create_router_network_graph() noexcept
{
  const auto g = create_router_network_graph();
  assert(get_n_edges(g) == 7);
  assert(get_n_vertices(g) == 5);
  //print_vertex_names(g); //Does not work
  //Check the router names and delay times
  assert(!"Green");
  std::cout << __func__ << ": TODO" << '\n';
}



