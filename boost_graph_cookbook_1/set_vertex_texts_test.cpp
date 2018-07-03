#include "set_vertex_texts.h"
//#include "set_vertex_texts_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_textd_vertices_k2_graph.h"
#include "get_vertex_texts.h"


BOOST_AUTO_TEST_CASE(set_vertex_texts_thorough)
{
  //Named K2 graph
  {
    auto g = create_textd_vertices_k2_graph();
    const std::vector<std::string> vertex_texts{"alpha", "beta"};
    set_vertex_texts(g,vertex_texts);
    BOOST_CHECK(get_vertex_texts(g) == vertex_texts);
  }
  
}
