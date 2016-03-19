#include "create_named_edges_and_vertices_petersen_graph.h"
#include "create_named_edges_and_vertices_petersen_graph_demo.impl"

#include <boost/test/unit_test.hpp>

#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_empty_undirected_graph.h"
#include "is_regular_file.h"
#include "save_named_edges_and_vertices_graph_to_dot.h"
#include "find_first_vertex_with_name.h"
#include "get_vertex_name.h"

BOOST_AUTO_TEST_CASE(create_named_edges_and_vertices_petersen_graph_thorough)
{
  //Basic tests
  {
    const auto g = create_named_edges_and_vertices_petersen_graph();
    using vertex_descriptor = decltype(create_named_edges_and_vertices_petersen_graph())::vertex_descriptor;
    BOOST_CHECK(boost::num_edges(g) == 15);
    BOOST_CHECK(boost::num_vertices(g) == 10);
    //Neighbours of small 'a' are 'A', 'c' and 'd'
    {
      const auto focal_vertex = find_first_vertex_with_name("a", g);
      const auto neighbours = boost::adjacent_vertices(focal_vertex, g);
      std::set<std::string> neighbour_names;
      std::transform(neighbours.first, neighbours.second,
        std::inserter(neighbour_names,std::begin(neighbour_names)),
        [&g](const vertex_descriptor& d)
        {
          return get_vertex_name(d,g);
        }
      );
      std::set<std::string> expected = { "A", "c", "d"};
      BOOST_CHECK(neighbour_names == expected);
    }
    //Neighbours of uppercase 'B' are 'A', 'C' and 'b'
    {
      const auto focal_vertex = find_first_vertex_with_name("B", g);
      const auto neighbours = boost::adjacent_vertices(focal_vertex, g);
      std::set<std::string> neighbour_names;
      std::transform(neighbours.first, neighbours.second,
        std::inserter(neighbour_names,std::begin(neighbour_names)),
        [&g](const vertex_descriptor& d)
        {
          return get_vertex_name(d,g);
        }
      );
      std::set<std::string> expected = { "A", "C", "b"};
      BOOST_CHECK(neighbour_names == expected);
    }
    //Neighbours of lowercase 'c' are 'C', 'a' and 'e'
    {
      const auto focal_vertex = find_first_vertex_with_name("c", g);
      const auto neighbours = boost::adjacent_vertices(focal_vertex, g);
      std::set<std::string> neighbour_names;
      std::transform(neighbours.first, neighbours.second,
        std::inserter(neighbour_names,std::begin(neighbour_names)),
        [&g](const vertex_descriptor& d)
        {
          return get_vertex_name(d,g);
        }
      );
      std::set<std::string> expected = { "C", "a", "e"};
      BOOST_CHECK(neighbour_names == expected);
    }
    //Neighbours of uppercase 'D' are 'd', 'C' and 'E'
    {
      const auto focal_vertex = find_first_vertex_with_name("D", g);
      const auto neighbours = boost::adjacent_vertices(focal_vertex, g);
      std::set<std::string> neighbour_names;
      std::transform(neighbours.first, neighbours.second,
        std::inserter(neighbour_names,std::begin(neighbour_names)),
        [&g](const vertex_descriptor& d)
        {
          return get_vertex_name(d,g);
        }
      );
      std::set<std::string> expected = { "d", "C", "E"};
      BOOST_CHECK(neighbour_names == expected);
    }
    //Neighbours of lowercase 'e' are 'E', 'b' and 'c'
    {
      const auto focal_vertex = find_first_vertex_with_name("e", g);
      const auto neighbours = boost::adjacent_vertices(focal_vertex, g);
      std::set<std::string> neighbour_names;
      std::transform(neighbours.first, neighbours.second,
        std::inserter(neighbour_names,std::begin(neighbour_names)),
        [&g](const vertex_descriptor& d)
        {
          return get_vertex_name(d,g);
        }
      );
      std::set<std::string> expected = { "E", "b", "c"};
      BOOST_CHECK(neighbour_names == expected);
    }
  }
  //Create the .dot and .svg of the 'create_k3_graph' chapter
  {

    const auto g = create_named_edges_and_vertices_petersen_graph();
    const std::string base_filename{"create_named_edges_and_vertices_petersen_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_named_edges_and_vertices_graph_to_dot(g,dot_filename);
    BOOST_CHECK(is_regular_file(dot_filename));
    convert_dot_to_svg(dot_filename,svg_filename);
    BOOST_CHECK(is_regular_file(svg_filename));
    copy_file(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
  }
  
}
