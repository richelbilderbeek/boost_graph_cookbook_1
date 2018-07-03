#include "get_vertex_texts.h"
#include "get_vertex_texts_demo.impl"


#include <boost/test/unit_test.hpp>

#include "create_k2_graph.h"
#include "add_textd_vertex.h"
#include "create_empty_undirected_textd_vertices_graph.h"
#include "create_textd_vertices_k2_graph.h"
#include "create_textd_edges_and_vertices_k3_graph.h"

BOOST_AUTO_TEST_CASE(get_vertex_texts_thorough)
{
  //Untextd K2 graph: should not compile, and it doesn't :-)
  {
    //get_vertex_texts(create_k2_graph());
  }
  //Named K2 graph
  {
    auto g = create_empty_undirected_textd_vertices_graph();
    const std::string vertex_text_1{"Chip"};
    const std::string vertex_text_2{"Chap"};
    add_textd_vertex(vertex_text_1, g);
    add_textd_vertex(vertex_text_2, g);
    const std::vector<std::string> expected_texts{vertex_text_1, vertex_text_2};
    const std::vector<std::string> vertex_texts{get_vertex_texts(g)};
    BOOST_CHECK(expected_texts == vertex_texts);
  }
  //Named K2 graph
  {
    const auto g = create_textd_vertices_k2_graph();
    const std::vector<std::string> expected_texts{"Me", "My computer"};
    const std::vector<std::string> vertex_texts{get_vertex_texts(g)};
    BOOST_CHECK(expected_texts == vertex_texts);
  }
  //Named K3 graph
  {
    const auto g = create_textd_edges_and_vertices_k3_graph();
    const std::vector<std::string> expected_texts{"top", "right", "left"};
    const std::vector<std::string> vertex_texts{get_vertex_texts(g)};
    BOOST_CHECK(expected_texts == vertex_texts);
  }
}
