#include "add_named_edge.h"
#include "add_named_edge_demo.impl"

#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test.hpp>

#include "create_empty_undirected_named_edges_and_vertices_graph.h"


#include "get_edge_names.h"

BOOST_AUTO_TEST_CASE(add_named_edge_thorough)
{
  //Add 1 edge
  {
    auto g = create_empty_undirected_named_edges_and_vertices_graph();
    BOOST_CHECK(boost::num_vertices(g) == 0);
    BOOST_CHECK(boost::num_edges(g) == 0);
    const std::string edge_name{"X"};
    add_named_edge(edge_name, g);
    BOOST_CHECK(boost::num_vertices(g) == 2);
    BOOST_CHECK(boost::num_edges(g) == 1);
    const std::vector<std::string> edge_names{get_edge_names(g)};
    const std::vector<std::string> expected_names{edge_name};
    BOOST_CHECK(edge_names == expected_names);
  }
  //Add 2 edges
  {
    auto g = create_empty_undirected_named_edges_and_vertices_graph();
    BOOST_CHECK(boost::num_vertices(g) == 0);
    BOOST_CHECK(boost::num_edges(g) == 0);
    const std::string edge_name_1{"A"};
    const std::string edge_name_2{"B"};
    add_named_edge(edge_name_1, g);
    add_named_edge(edge_name_2, g);
    BOOST_CHECK(boost::num_vertices(g) == 4);
    BOOST_CHECK(boost::num_edges(g) == 2);
    const std::vector<std::string> edge_names{get_edge_names(g)};
    const std::vector<std::string> expected_names{edge_name_1,edge_name_2};
    BOOST_CHECK(edge_names == expected_names);
  }
}
