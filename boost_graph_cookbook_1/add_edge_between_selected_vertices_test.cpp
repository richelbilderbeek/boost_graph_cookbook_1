#include "add_edge_between_selected_vertices.h"
#include "add_edge_between_selected_vertices_demo.impl"

#include <boost/test/unit_test.hpp>

#include "add_custom_and_selectable_vertex.h"
#include "add_edge_between_selected_vertices.h"
#include "create_empty_undirected_custom_and_selectable_vertices_graph.h"

BOOST_AUTO_TEST_CASE(add_edge_between_selected_vertices_once)
{
  auto g = create_empty_undirected_custom_and_selectable_vertices_graph();
  add_custom_and_selectable_vertex(my_custom_vertex("Bert"), true, g);
  add_custom_and_selectable_vertex(my_custom_vertex("Ernie"), true, g);
  add_edge_between_selected_vertices(g);
  BOOST_CHECK(boost::num_edges(g) == 1);
}

BOOST_AUTO_TEST_CASE(add_edge_between_selected_vertices_another_type)
{
  using another_vertex = std::string;
  using another_graph
    = boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
      boost::property<boost::vertex_custom_type_t, another_vertex,
        boost::property<boost::vertex_is_selected_t, bool>>>;

  another_graph g;
  add_custom_and_selectable_vertex(another_vertex("Bert"), true, g);
  add_custom_and_selectable_vertex(another_vertex("Ernie"), true, g);
  add_edge_between_selected_vertices(g);
  BOOST_CHECK(boost::num_edges(g) == 1);
}
