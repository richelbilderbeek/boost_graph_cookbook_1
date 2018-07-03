#include "create_nasty_directed_text_vertices_graph.h"

#include <boost/test/unit_test.hpp>

#include "add_text_vertex.h"
#include "create_empty_directed_text_vertices_graph.h"
#include "get_sorted_vertex_texts.h"
#include "load_directed_text_vertices_graph_from_dot.h"
#include "save_text_vertices_graph_to_dot.h"

BOOST_AUTO_TEST_CASE(create_nasty_directed_text_vertices_graph_thorough)
{
  {
    auto g = create_nasty_directed_text_vertices_graph();
    const std::string filetext{
      "create_nasty_directed_text_vertices_graph_test.dot"
    };
    save_text_vertices_graph_to_dot(g, filetext);
    const auto h = load_directed_text_vertices_graph_from_dot(filetext);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    const auto a = get_sorted_vertex_texts(g);
    const auto b = get_sorted_vertex_texts(h);
    BOOST_CHECK(a == b);
  }
}
