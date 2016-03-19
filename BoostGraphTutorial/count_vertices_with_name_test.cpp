#include "count_vertices_with_name.h"
#include "count_vertices_with_name_demo.impl"


#include <boost/test/unit_test.hpp>


#include "create_empty_undirected_named_vertices_graph.h"
#include "add_named_vertex.h"

BOOST_AUTO_TEST_CASE(count_vertices_with_name_thorough)
{
  {
    auto g = create_empty_undirected_named_vertices_graph();
    add_named_vertex("Rex", g);
    BOOST_CHECK(count_vertices_with_name("Rex", g) == 1);
    BOOST_CHECK(count_vertices_with_name("Nebular", g) == 0);
  }
}
