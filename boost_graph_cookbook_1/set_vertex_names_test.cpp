#include "set_vertex_names.h"
//#include "set_vertex_names_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_named_vertices_k2_graph.h"
#include "get_vertex_names.h"

BOOST_AUTO_TEST_CASE(set_vertex_names_thorough)
{
  // Named K2 graph
  {
    auto g = create_named_vertices_k2_graph();
    const std::vector<std::string> vertex_names{ "alpha", "beta" };
    set_vertex_names(g, vertex_names);
    BOOST_CHECK(get_vertex_names(g) == vertex_names);
  }
}
