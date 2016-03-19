#include "create_nasty_undirected_custom_and_selectable_vertices_graph.h"



#include "add_custom_and_selectable_vertex.h"
#include "create_empty_undirected_custom_and_selectable_vertices_graph.h"
#include "save_custom_and_selectable_vertices_graph_to_dot.h"
#include "load_undirected_custom_and_selectable_vertices_graph_from_dot.h"
#include "get_sorted_custom_vertex_my_vertexes.h"
#include "get_sorted_vertex_selectednesses.h"
#include "convert_dot_to_svg.h"
#include "copy_file.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS,
  boost::property<
    boost::vertex_custom_type_t, my_custom_vertex,
    boost::property<
      boost::vertex_is_selected_t, bool
    >
  >
>
create_nasty_undirected_custom_and_selectable_vertices_graph() noexcept
{
  auto g = create_empty_undirected_custom_and_selectable_vertices_graph();

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
    //Long name
    add_custom_and_selectable_vertex(my_custom_vertex(std::string(999,'A'),std::string(999,'B')), i % 2, g);
    //Escape sequence
    add_custom_and_selectable_vertex(my_custom_vertex("A\"];","B\"];"), i % 2, g);
  }
  return g;
}

