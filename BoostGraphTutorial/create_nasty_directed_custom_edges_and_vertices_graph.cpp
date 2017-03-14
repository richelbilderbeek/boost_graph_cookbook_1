#include "create_nasty_directed_custom_edges_and_vertices_graph.h"



#include "add_custom_edge.h"
#include "create_empty_directed_custom_edges_and_vertices_graph.h"
#include "load_directed_custom_edges_and_vertices_graph_from_dot.h"
#include "get_sorted_custom_edge_my_edges.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::property<
    boost::vertex_custom_type_t, my_custom_vertex
  >,
  boost::property<
    boost::edge_custom_type_t,my_custom_edge
  >
>
create_nasty_directed_custom_edges_and_vertices_graph() noexcept
{
  auto g = create_empty_directed_custom_edges_and_vertices_graph();

  for (int i=0; i!=2; ++i) //Duplicate labels
  {
    //Normal
    add_custom_edge(my_custom_edge("A","BCDEFGHIJKLMN"), g);
    //Spaces
    add_custom_edge(my_custom_edge("A B"," C D"), g);
    //Spaces in end and front
    add_custom_edge(my_custom_edge(" A B ","  C  D  "), g);
    //Underscores
    add_custom_edge(my_custom_edge("A_B","C_D"), g);
    //Backslash
    add_custom_edge(my_custom_edge("A\\B","C\\D"), g);
    //Quotes
    add_custom_edge(my_custom_edge("A\"B","C\"D"), g);
    //Commas
    add_custom_edge(my_custom_edge("A,B",",C,D,"), g);
    //Escape sequence
    add_custom_edge(my_custom_edge("A\"];","B\"];"), g);
  }
  return g;
}

