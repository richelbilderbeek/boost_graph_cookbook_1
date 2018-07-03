#include "create_text_vertices_petersen_graph.h"
#include "create_text_vertices_petersen_graph_demo.impl"

#include <boost/test/unit_test.hpp>

#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_empty_undirected_graph.h"
#include "find_first_vertex_with_text.h"
#include "get_vertex_text.h"
#include "is_regular_file.h"
#include "save_text_vertices_graph_to_dot.h"

BOOST_AUTO_TEST_CASE(create_text_vertices_petersen_graph_thorough)
{
  // Basic tests
  {
    const auto g = create_text_vertices_petersen_graph();
    using vertex_descriptor
      = decltype(create_text_vertices_petersen_graph())::vertex_descriptor;
    BOOST_CHECK(boost::num_edges(g) == 15);
    BOOST_CHECK(boost::num_vertices(g) == 10);
    // Neighbours of small 'a' are 'A', 'c' and 'd'
    {
      const auto focal_vertex = find_first_vertex_with_text("a", g);
      const auto neighbours = boost::adjacent_vertices(focal_vertex, g);
      std::set<std::string> neighbour_texts;
      std::transform(neighbours.first, neighbours.second,
        std::inserter(neighbour_texts, std::begin(neighbour_texts)),
        [&g](const vertex_descriptor& d) { return get_vertex_text(d, g); });
      std::set<std::string> expected = { "A", "c", "d" };
      BOOST_CHECK(neighbour_texts == expected);
    }
    // Neighbours of uppercase 'B' are 'A', 'C' and 'b'
    {
      const auto focal_vertex = find_first_vertex_with_text("B", g);
      const auto neighbours = boost::adjacent_vertices(focal_vertex, g);
      std::set<std::string> neighbour_texts;
      std::transform(neighbours.first, neighbours.second,
        std::inserter(neighbour_texts, std::begin(neighbour_texts)),
        [&g](const vertex_descriptor& d) { return get_vertex_text(d, g); });
      std::set<std::string> expected = { "A", "C", "b" };
      BOOST_CHECK(neighbour_texts == expected);
    }
    // Neighbours of lowercase 'c' are 'C', 'a' and 'e'
    {
      const auto focal_vertex = find_first_vertex_with_text("c", g);
      const auto neighbours = boost::adjacent_vertices(focal_vertex, g);
      std::set<std::string> neighbour_texts;
      std::transform(neighbours.first, neighbours.second,
        std::inserter(neighbour_texts, std::begin(neighbour_texts)),
        [&g](const vertex_descriptor& d) { return get_vertex_text(d, g); });
      std::set<std::string> expected = { "C", "a", "e" };
      BOOST_CHECK(neighbour_texts == expected);
    }
    // Neighbours of uppercase 'D' are 'd', 'C' and 'E'
    {
      const auto focal_vertex = find_first_vertex_with_text("D", g);
      const auto neighbours = boost::adjacent_vertices(focal_vertex, g);
      std::set<std::string> neighbour_texts;
      std::transform(neighbours.first, neighbours.second,
        std::inserter(neighbour_texts, std::begin(neighbour_texts)),
        [&g](const vertex_descriptor& d) { return get_vertex_text(d, g); });
      std::set<std::string> expected = { "d", "C", "E" };
      BOOST_CHECK(neighbour_texts == expected);
    }
    // Neighbours of lowercase 'e' are 'E', 'b' and 'c'
    {
      const auto focal_vertex = find_first_vertex_with_text("e", g);
      const auto neighbours = boost::adjacent_vertices(focal_vertex, g);
      std::set<std::string> neighbour_texts;
      std::transform(neighbours.first, neighbours.second,
        std::inserter(neighbour_texts, std::begin(neighbour_texts)),
        [&g](const vertex_descriptor& d) { return get_vertex_text(d, g); });
      std::set<std::string> expected = { "E", "b", "c" };
      BOOST_CHECK(neighbour_texts == expected);
    }
  }
  // Create the .dot and .svg of the 'create_k3_graph' chapter
  {

    const auto g = create_text_vertices_petersen_graph();
    const std::string base_filetext{ "create_text_vertices_petersen_graph" };
    const std::string dot_filetext{ base_filetext + ".dot" };
    const std::string svg_filetext{ base_filetext + ".svg" };
    save_text_vertices_graph_to_dot(g, dot_filetext);
    BOOST_CHECK(is_regular_file(dot_filetext));
    convert_dot_to_svg(dot_filetext, svg_filetext);
    BOOST_CHECK(is_regular_file(svg_filetext));
    copy_file(dot_filetext, "../boost_graph_cookbook_1/" + dot_filetext,
      copy_file_mode::allow_overwrite);
    copy_file(svg_filetext, "../boost_graph_cookbook_1/" + svg_filetext,
      copy_file_mode::allow_overwrite);
    std::remove(dot_filetext.c_str());
    std::remove(svg_filetext.c_str());
  }
}
