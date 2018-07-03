#include <boost/test/unit_test.hpp>
#include "get_sorted_vertex_texts.h"
//#include "get_sorted_vertex_texts_demo.impl"
#include "create_textd_vertices_path_graph.h"

BOOST_AUTO_TEST_CASE(get_sorted_vertex_texts_thorough)
{
  const auto g = create_textd_vertices_path_graph(
    {"F", "B", "A", "C", "E", "D"}
  );
  const std::vector<std::string> expected{
    "A", "B", "C", "D", "E", "F"
  };
  const auto found = get_sorted_vertex_texts(g);
  BOOST_CHECK(found == expected);
}
