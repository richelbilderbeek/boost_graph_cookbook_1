#include "create_nasty_undirected_bundled_edges_and_vertices_graph.h"



#include "add_bundled_edge.h"
#include "add_bundled_vertex.h"
#include "create_empty_undirected_bundled_edges_and_vertices_graph.h"
#include "save_bundled_edges_and_vertices_graph_to_dot.h"
#include "load_undirected_bundled_edges_and_vertices_graph_from_dot.h"
#include "get_sorted_bundled_edge_my_edges.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  my_bundled_vertex,
  my_bundled_edge
>
create_nasty_undirected_bundled_edges_and_vertices_graph() noexcept
{
  auto g = create_empty_undirected_bundled_edges_and_vertices_graph();

  const auto vd_1 = add_bundled_vertex(my_bundled_vertex("A","BCDEFGHIJKLMN"), g);
  //Spaces
  const auto vd_2 = add_bundled_vertex(my_bundled_vertex("A B"," C D"), g);
  //Spaces in end and front
  const auto vd_3 = add_bundled_vertex(my_bundled_vertex(" A B ","  C  D  "), g);
  //Underscores
  const auto vd_4 = add_bundled_vertex(my_bundled_vertex("A_B","C_D"), g);
  //Backslash
  const auto vd_5 = add_bundled_vertex(my_bundled_vertex("A\\B","C\\D"), g);
  //Quotes
  const auto vd_6 = add_bundled_vertex(my_bundled_vertex("A\"B","C\"D"), g);
  //Commas
  const auto vd_7 = add_bundled_vertex(my_bundled_vertex("A,B",",C,D,"), g);
  //Square brackets
  const auto vd_8 = add_bundled_vertex(my_bundled_vertex("A[B",",C]D,"), g);
  //Curly braces
  const auto vd_9 = add_bundled_vertex(my_bundled_vertex("A{B",",C}D,"), g);
  //Colon, semicolon
  const auto vd_10 = add_bundled_vertex(my_bundled_vertex("A:B",",C;D,"), g);
  //Dollar, at
  const auto vd_11 = add_bundled_vertex(my_bundled_vertex("A$B",",C@D,"), g);
  //Escape sequence
  const auto vd_12 = add_bundled_vertex(my_bundled_vertex("A\"];","B\"];"), g);

  //Normal
  add_bundled_edge(vd_1, vd_2, my_bundled_edge("A","BCDEFGHIJKLMN"), g);
  //Spaces
  add_bundled_edge(vd_3, vd_4, my_bundled_edge("A B"," C D"), g);
  //Spaces in end and front
  add_bundled_edge(vd_5, vd_6, my_bundled_edge(" A B ","  C  D  "), g);
  //Underscores
  add_bundled_edge(vd_7, vd_8, my_bundled_edge("A_B","C_D"), g);
  //Backslash
  add_bundled_edge(vd_9, vd_10, my_bundled_edge("A\\B","C\\D"), g);
  //Quotes
  add_bundled_edge(vd_11, vd_12, my_bundled_edge("A\"B","C\"D"), g);
  //Commas
  add_bundled_edge(vd_1, vd_3, my_bundled_edge("A,B",",C,D,"), g);
  //Escape sequence
  add_bundled_edge(vd_3, vd_5, my_bundled_edge("A\"];","B\"];"), g);

  return g;
}

