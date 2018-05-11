#include "find_first_custom_edge.h"
#include "find_first_custom_edge_demo.impl"

#include <boost/test/unit_test.hpp>
#include "create_custom_edges_and_vertices_k3_graph.h"
#include "create_empty_directed_custom_edges_and_vertices_graph.h"
#include "get_my_custom_edge.h"

BOOST_AUTO_TEST_CASE(find_first_custom_edge_thorough)
{
  //Search for name
  {
    const auto g = create_custom_edges_and_vertices_k3_graph();
    const auto predicate = [](const my_custom_edge& e) { return e.get_name() == "BC"; };
    const auto ed = find_first_custom_edge(predicate, g);
    const auto edge = get_my_custom_edge(ed, g);
    BOOST_CHECK(edge.get_name() == "BC");
    BOOST_CHECK(edge.get_description() == "second");
  }
  //Search for description
  {
    const auto g = create_custom_edges_and_vertices_k3_graph();
    const auto predicate = [](const my_custom_edge& e) { return e.get_description() == "second"; };
    const auto ed = find_first_custom_edge(predicate, g);
    const auto edge = get_my_custom_edge(ed, g);
    BOOST_CHECK(edge.get_name() == "BC");
    BOOST_CHECK(edge.get_description() == "second");
  }
}


BOOST_AUTO_TEST_CASE(find_first_custom_edge_when_edge_is_absent)
{
  const auto g = create_empty_directed_custom_edges_and_vertices_graph();
  const auto predicate = [](const my_custom_edge& e) { return e.get_name() == "some absent name"; };
  BOOST_CHECK_THROW(
    find_first_custom_edge(predicate, g),
    std::invalid_argument
  );
}

