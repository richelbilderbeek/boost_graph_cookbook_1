#include "create_nasty_directed_custom_and_selectable_edges_and_vertices_graph.h"



#include "add_custom_and_selectable_edge.h"
#include "add_custom_and_selectable_vertex.h"
#include "create_empty_directed_custom_and_selectable_edges_and_vertices_graph.h"
#include "save_custom_and_selectable_edges_and_vertices_graph_to_dot.h"
#include "load_directed_custom_and_selectable_edges_and_vertices_graph_from_dot.h"
#include "get_sorted_custom_vertex_my_vertexes.h"
#include "get_sorted_vertex_selectednesses.h"
#include "convert_dot_to_svg.h"
#include "copy_file.h"

#include "create_empty_directed_custom_and_selectable_edges_and_vertices_graph.h"
#include "install_vertex_custom_type.h"
#include "install_vertex_is_selected.h"
#include "my_custom_vertex.h"
#include "add_custom_and_selectable_vertex.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::property<
    boost::vertex_custom_type_t, my_custom_vertex,
    boost::property<
      boost::vertex_is_selected_t, bool
    >
  >,
  boost::property<
    boost::edge_custom_type_t, my_custom_edge,
    boost::property<
      boost::edge_is_selected_t, bool
    >
  >
>
create_nasty_directed_custom_and_selectable_edges_and_vertices_graph() noexcept
{
  auto g = create_empty_directed_custom_and_selectable_edges_and_vertices_graph();

  for (int i=0; i!=3; ++i) //Duplicate labels
  {
    //Normal
    add_custom_and_selectable_vertex(my_custom_vertex("A","BCDEFGHIJKLMN"), i % 2, g);
    //Spaces
    add_custom_and_selectable_vertex(my_custom_vertex("A B"," C D"), i % 2, g);
    //Spaces in end and front
    add_custom_and_selectable_vertex(my_custom_vertex(" A B ","  C  D  "), i % 2, g);
    //Underscores
    add_custom_and_selectable_vertex(my_custom_vertex("A_B","C_D"), i % 2, g);
    //Backslash
    add_custom_and_selectable_vertex(my_custom_vertex("A\\B","C\\D"), i % 2, g);
    //Quotes
    add_custom_and_selectable_vertex(my_custom_vertex("A\"B","C\"D"), i % 2, g);
    //Commas
    add_custom_and_selectable_vertex(my_custom_vertex("A,B",",C,D,"), i % 2, g);
    //Tags
    add_custom_and_selectable_vertex(my_custom_vertex("A<B",",C>D,"), i % 2, g);
    //Escape sequence
    add_custom_and_selectable_vertex(my_custom_vertex("A\"];","B\"];"), i % 2, g);
  }

  for (int i=0; i!=3; ++i) //Duplicate labels
  {
    //Normal
    add_custom_and_selectable_edge(my_custom_edge("A","BCDEFGHIJKLMN"), i % 2, g);
    //Spaces
    add_custom_and_selectable_edge(my_custom_edge("A B"," C D"), i % 2, g);
    //Spaces in end and front
    add_custom_and_selectable_edge(my_custom_edge(" A B ","  C  D  "), i % 2, g);
    //Underscores
    add_custom_and_selectable_edge(my_custom_edge("A_B","C_D"), i % 2, g);
    //Backslash
    add_custom_and_selectable_edge(my_custom_edge("A\\B","C\\D"), i % 2, g);
    //Quotes
    add_custom_and_selectable_edge(my_custom_edge("A\"B","C\"D"), i % 2, g);
    //Commas
    add_custom_and_selectable_edge(my_custom_edge("A,B",",C,D,"), i % 2, g);
    //Tags
    add_custom_and_selectable_edge(my_custom_edge("A<B",",C>D,"), i % 2, g);
    //Escape sequence
    add_custom_and_selectable_edge(my_custom_edge("A\"];","B\"];"), i % 2, g);
  }
  return g;
}

