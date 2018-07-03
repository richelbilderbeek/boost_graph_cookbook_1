#include "add_text_and_selectable_vertex.h"
#include "add_text_and_selectable_vertex_demo.impl"

#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test.hpp>

#include "create_empty_directed_text_and_selectable_vertices_graph.h"


#include "get_vertex_names.h"
#include "get_vertex_descriptors.h"
#include "get_edge_descriptors.h"

BOOST_AUTO_TEST_CASE(add_text_and_selectable_vertex_add_one)
{
  auto g = create_empty_directed_text_and_selectable_vertices_graph();
  BOOST_CHECK(get_vertex_descriptors(g).size() == 0);
  BOOST_CHECK(get_edge_descriptors(g).size() == 0);
  BOOST_CHECK(boost::num_vertices(g) == 0);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const std::string vertex_name{"X"};
  add_text_and_selectable_vertex(vertex_name, true, g);
  BOOST_CHECK(get_vertex_descriptors(g).size() == 1);
  BOOST_CHECK(get_edge_descriptors(g).size() == 0);
  BOOST_CHECK(boost::num_vertices(g) == 1);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const std::vector<std::string> vertex_names{get_vertex_names(g)};
  const std::vector<std::string> expected_names{vertex_name};
  BOOST_CHECK(vertex_names == expected_names);
}

BOOST_AUTO_TEST_CASE(add_text_and_selectable_vertex_add_two)
{
  auto g = create_empty_directed_text_and_selectable_vertices_graph();
  BOOST_CHECK(boost::num_vertices(g) == 0);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const std::string vertex_name_1{"A"};
  const std::string vertex_name_2{"B"};
  add_text_and_selectable_vertex(vertex_name_1, true, g);
  add_text_and_selectable_vertex(vertex_name_2, false, g);
  BOOST_CHECK(boost::num_vertices(g) == 2);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const std::vector<std::string> vertex_names{get_vertex_names(g)};
  const std::vector<std::string> expected_names{vertex_name_1,vertex_name_2};
  BOOST_CHECK(vertex_names == expected_names);
}
