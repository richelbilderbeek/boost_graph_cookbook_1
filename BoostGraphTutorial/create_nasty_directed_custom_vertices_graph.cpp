#include "create_nasty_directed_custom_vertices_graph.h"

#include <cassert>
#include "add_custom_vertex.h"
#include "create_empty_directed_custom_vertices_graph.h"
#include "save_custom_vertices_graph_to_dot.h"
#include "load_directed_custom_vertices_graph_from_dot.h"
#include "get_sorted_custom_vertex_my_vertexes.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::property<
    boost::vertex_custom_type_t, my_custom_vertex
  >
>
create_nasty_directed_custom_vertices_graph() noexcept
{
  auto g = create_empty_directed_custom_vertices_graph();

  for (int i=0; i!=2; ++i) //Duplicate labels
  {
    //Normal
    add_custom_vertex(my_custom_vertex("A","BCDEFGHIJKLMN"), g);
    //Spaces
    add_custom_vertex(my_custom_vertex("A B"," C D"), g);
    //Spaces in end and front
    add_custom_vertex(my_custom_vertex(" A B ","  C  D  "), g);
    //Underscores
    add_custom_vertex(my_custom_vertex("A_B","C_D"), g);
    //Backslash
    add_custom_vertex(my_custom_vertex("A\\B","C\\D"), g);
    //Quotes
    add_custom_vertex(my_custom_vertex("A\"B","C\"D"), g);
    //Commas
    add_custom_vertex(my_custom_vertex("A,B",",C,D,"), g);
    //Escape sequence
    add_custom_vertex(my_custom_vertex("A\"];","B\"];"), g);
  }
  return g;
}


void create_nasty_directed_custom_vertices_graph_test() noexcept
{
  {
    auto g = create_nasty_directed_custom_vertices_graph();
    const std::string filename{
      "create_nasty_directed_custom_vertices_graph_test.dot"
    };
    save_custom_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_custom_vertices_graph_from_dot(filename);
    assert(boost::num_edges(g) == boost::num_edges(h));
    assert(boost::num_vertices(g) == boost::num_vertices(h));
    const auto a = get_sorted_custom_vertex_my_vertexes(g);
    const auto b = get_sorted_custom_vertex_my_vertexes(h);
    assert(a == b);
  }
  std::cout << __func__ << ": OK" << '\n';
}
