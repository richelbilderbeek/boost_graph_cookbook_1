#include "create_nasty_directed_custom_vertices_graph.h"

#include "add_custom_vertex.h"
#include "create_empty_directed_custom_vertices_graph.h"
#include "get_sorted_custom_vertex_my_vertexes.h"

boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS,
  boost::property<boost::vertex_custom_type_t, my_custom_vertex>>
create_nasty_directed_custom_vertices_graph() noexcept
{
  auto g = create_empty_directed_custom_vertices_graph();

  for (int i = 0; i != 2; ++i) // Duplicate labels
  {
    // Normal
    add_custom_vertex(my_custom_vertex("A", "BCDEFGHIJKLMN"), g);
    // Spaces
    add_custom_vertex(my_custom_vertex("A B", " C D"), g);
    // Spaces in end and front
    add_custom_vertex(my_custom_vertex(" A B ", "  C  D  "), g);
    // Underscores
    add_custom_vertex(my_custom_vertex("A_B", "C_D"), g);
    // Backslash
    add_custom_vertex(my_custom_vertex("A\\B", "C\\D"), g);
    // Quotes
    add_custom_vertex(my_custom_vertex("A\"B", "C\"D"), g);
    // Commas
    add_custom_vertex(my_custom_vertex("A,B", ",C,D,"), g);
    // Escape sequence
    add_custom_vertex(my_custom_vertex("A\"];", "B\"];"), g);
  }
  return g;
}
