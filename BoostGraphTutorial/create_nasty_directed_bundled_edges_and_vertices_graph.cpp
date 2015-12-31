#include "create_nasty_directed_bundled_edges_and_vertices_graph.h"

#include <cassert>
#include "add_bundled_edge.h"
#include "create_empty_directed_bundled_edges_and_vertices_graph.h"
#include "save_bundled_edges_and_vertices_graph_to_dot.h"
#include "load_directed_bundled_edges_and_vertices_graph_from_dot.h"
#include "get_sorted_bundled_edge_my_edges.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  my_bundled_vertex,
  my_bundled_edge
>
create_nasty_directed_bundled_edges_and_vertices_graph() noexcept
{
  auto g = create_empty_directed_bundled_edges_and_vertices_graph();

  for (int i=0; i!=2; ++i) //Duplicate labels
  {
    //Normal
    add_bundled_edge(my_bundled_edge("A","BCDEFGHIJKLMN"), g);
    //Spaces
    add_bundled_edge(my_bundled_edge("A B"," C D"), g);
    //Spaces in end and front
    add_bundled_edge(my_bundled_edge(" A B ","  C  D  "), g);
    //Underscores
    add_bundled_edge(my_bundled_edge("A_B","C_D"), g);
    //Backslash
    add_bundled_edge(my_bundled_edge("A\\B","C\\D"), g);
    //Quotes
    add_bundled_edge(my_bundled_edge("A\"B","C\"D"), g);
    //Commas
    add_bundled_edge(my_bundled_edge("A,B",",C,D,"), g);
    //Escape sequence
    add_bundled_edge(my_bundled_edge("A\"];","B\"];"), g);
  }
  return g;
}

void create_nasty_directed_bundled_edges_and_vertices_graph_test() noexcept
{
  {
    auto g = create_nasty_directed_bundled_edges_and_vertices_graph();
    const std::string filename{
      "create_nasty_directed_bundled_edges_and_vertices_graph_test.dot"
    };
    save_bundled_edges_and_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_bundled_edges_and_vertices_graph_from_dot(filename);
    assert(boost::num_edges(g) == boost::num_edges(h));
    assert(boost::num_vertices(g) == boost::num_vertices(h));
    //get_my_bundled_edges returns the unsorted edge,
    //to compare the my_bundled_edges before and after, its results must be sorted
    const auto a = get_sorted_bundled_edge_my_edges(g);
    const auto b = get_sorted_bundled_edge_my_edges(h);
    assert(a == b);
  }
  std::cout << __func__ << ": OK" << '\n';
}
