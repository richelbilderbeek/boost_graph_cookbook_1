#include "create_nasty_directed_text_vertices_graph.h"

#include "add_text_vertex.h"
#include "create_empty_directed_text_vertices_graph.h"
#include "get_sorted_text_vertex_my_vertexes.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  std::string
>
create_nasty_directed_text_vertices_graph() noexcept
{
  auto g = create_empty_directed_text_vertices_graph();
  for (int i=0; i!=2; ++i) //Duplicate labels
  {
    //Normal
    add_text_vertex("A", g);
    //Spaces
    add_text_vertex("A B", g);
    //Spaces in end and front
    add_text_vertex(" A B", g);
    add_text_vertex("A B ", g);
    //Underscores
    add_text_vertex(" _A_B _ ", g);
    //Backslash
    add_text_vertex(" \\\\A\\B\\ ", g);
    //Quotes
    add_text_vertex(" \"A\"B\"\" ", g);
    //Commas
    add_text_vertex(" A,B,, ", g);
    //Long name
    add_text_vertex(std::string(999,'A') + std::string(999,'B'), g);
    //Escape sequence
    add_text_vertex("A\"];", g);
  }
  return g;
}


