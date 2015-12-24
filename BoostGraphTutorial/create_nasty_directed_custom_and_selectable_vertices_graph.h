#ifndef CREATE_NASTY_DIRECTED_CUSTOM_AND_SELECTABLE_VERTICES_GRAPH_H
#define CREATE_NASTY_DIRECTED_CUSTOM_AND_SELECTABLE_VERTICES_GRAPH_H

#include "create_empty_directed_custom_and_selectable_vertices_graph.h"
#include <boost/graph/adjacency_list.hpp>
#include "install_vertex_custom_type.h"
#include "install_vertex_is_selected.h"
#include "my_custom_vertex.h"
#include "add_custom_and_selectable_vertex.h"

template<
  typename my_custom_vertex_type = my_custom_vertex,
  typename is_selected_type = bool
>
boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::property<
    boost::vertex_custom_type_t, my_custom_vertex_type,
    boost::property<
      boost::vertex_is_selected_t, is_selected_type
    >
  >
>
create_nasty_directed_custom_and_selectable_vertices_graph() noexcept
{
  auto g = create_empty_directed_custom_and_selectable_vertices_graph();

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
    //Escape sequence
    add_custom_and_selectable_vertex(my_custom_vertex("A\"];","B\"];"), i % 2, g);
  }
  return g;
}

void create_nasty_directed_custom_and_selectable_vertices_graph_test() noexcept;

#endif // CREATE_NASTY_DIRECTED_CUSTOM_AND_SELECTABLE_VERTICES_GRAPH_H
