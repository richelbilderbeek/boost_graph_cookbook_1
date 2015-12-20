#include "remove_first_vertex_with_name.h"

#include "remove_first_vertex_with_name_demo.impl"

#include <cassert>
#include <iostream>

#include "create_named_vertices_k2_graph.h"



void remove_first_vertex_with_name_test() noexcept
{
  //Clean behavior
  {
    auto g = create_named_vertices_k2_graph();
    assert(boost::num_edges(g) == 1);
    assert(boost::num_vertices(g) == 2);
    clear_first_vertex_with_name("A",g);
    remove_first_vertex_with_name("A",g);
    assert(boost::num_edges(g) == 0);
    assert(boost::num_vertices(g) == 1);
  }
  #ifdef REMOVE_VERTEX_WITHOUT_CLEARING
  //Remove the vertex without clearing
  {
    auto g = create_named_vertices_k2_graph();
    assert(boost::num_edges(g) == 1);
    assert(boost::num_vertices(g) == 2);
    remove_first_vertex_with_name("A",g); //Will keep the edge??? Will be checked by assert
    assert(!has_vertex_with_name("A",g));
    assert(boost::num_edges(g) == 1);
    assert(boost::num_vertices(g) == 1);
  }
  #endif // REMOVE_VERTEX_WITHOUT_CLEARING
  remove_first_vertex_with_name_demo();
  std::cout << __func__ << ": OK" << '\n';
}
