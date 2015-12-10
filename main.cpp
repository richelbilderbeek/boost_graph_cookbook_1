#include "add_custom_edge.h"
#include "add_custom_vertex.h"
#include "add_edge.h"
#include "add_named_edge.h"
#include "add_named_vertex.h"
#include "add_vertex.h"
#include "bfs_name_printer.h"
#include "build_router_network.h"
#include "clear_first_vertex_with_name.h"
#include "count_vertices_with_name.h"
#include "create_custom_edges_and_vertices_k3_graph.h"
#include "create_custom_vertices_k2_graph.h"
#include "create_empty_custom_edges_and_vertices_graph.h"
#include "create_empty_custom_vertices_graph.h"
#include "create_empty_directed_graph.h"
#include "create_empty_named_edges_and_vertices_graph.h"
#include "create_empty_named_vertices_graph.h"
#include "create_empty_undirected_graph.h"
#include "create_empty_undirected_graph.h"
#include "create_k2_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"
#include "create_named_vertices_k2_graph.h"
#include "create_router_network_graph.h"
#include "create_router_network.h"
#include "create_tutorial_chapters_graph.h"
#include "find_first_edge_with_name.h"
#include "find_first_vertex_with_name.h"
#include "get_edge_descriptors.h"
#include "get_edge_my_edges.h"
#include "get_edge_name.h"
#include "get_edge_names.h"
#include "get_edges.h"
#include "get_first_vertex_with_name_out_degree.h"
#include "get_n_edges.h"
#include "get_n_vertices.h"
#include "get_type_name.h"
#include "get_vertex_descriptors.h"
#include "get_vertex_my_vertexes.h"
#include "get_vertex_name.h"
#include "get_vertex_names.h"
#include "get_vertex_out_degrees.h"
#include "get_vertices.h"
#include "has_edge_with_name.h"
#include "has_vertex_with_name.h"
#include "is_self_loop.h"
#include "is_valid_dot_file.h"
#include "print_trans_delay.h"
#include "print_trans_delays.h"
#include "print_vertex_name.h"
#include "print_vertex_names.h"
#include "remove_first_vertex_with_name.h"
#include "save_custom_vertices_graph_to_dot.h"
#include "save_graph_to_dot.h"
#include "save_named_edges_and_vertices_graph_to_dot.h"
#include "save_named_vertices_graph_to_dot.h"
#include "set_edge_name.h"
//#include "set_edge_my_edges.h"
#include "set_vertex_my_vertexes.h"
#include "set_vertex_name.h"
#include "set_vertex_names.h"

#include <iostream>

int main()
{
  add_custom_edge_test();
  add_custom_vertex_test();
  add_edge_test();
  add_named_edge_test();
  add_named_vertex_test();
  add_vertex_test();
  bfs_name_printer_test();
  build_router_network_test();
  clear_first_vertex_with_name_test();
  count_vertices_with_name_test();
  create_custom_edges_and_vertices_k3_graph_test();
  create_custom_vertices_k2_graph_test();
  create_empty_custom_edges_and_vertices_graph_test();
  create_empty_custom_vertices_graph_test();
  create_empty_directed_graph_test();
  create_empty_named_edges_and_vertices_graph_test();
  create_empty_named_vertices_graph_test();
  create_empty_undirected_graph_test();
  create_k2_graph_test();
  create_named_edges_and_vertices_k3_graph_test();
  create_named_vertices_k2_graph_test();
  create_router_network_graph_test();
  create_router_network_test();
  create_tutorial_chapters_graph_test();
  find_first_edge_with_name_test();
  find_first_vertex_with_name_test();
  get_edge_descriptors_test();
  get_edge_my_edges_test();
  get_edge_names_test();
  get_edge_name_test();
  get_edges_test();
  get_first_vertex_with_name_out_degree_test();
  get_n_vertices_test();
  get_type_name_test();
  get_vertex_descriptors_test();
  get_vertex_my_vertexes_test();
  get_vertex_names_test();
  get_vertex_name_test();
  get_vertex_out_degrees_test();
  get_vertices_test();
  has_edge_with_name_test();
  has_vertex_with_name_test();
  is_self_loop_test();
  is_valid_dot_file_test();
  print_trans_delays_test();
  print_trans_delay_test();
  print_vertex_names_test();
  print_vertex_name_test();
  remove_first_vertex_with_name_test();
  save_custom_vertices_graph_to_dot_test();
  save_graph_to_dot_test();
  save_named_edges_and_vertices_graph_to_dot_test();
  save_named_vertices_graph_to_dot_test();
  set_edge_name_test();
  set_vertex_my_vertexes_test();
  set_vertex_names_test();
  set_vertex_name_test();
  std::cout << "Done" << std::endl;
}
