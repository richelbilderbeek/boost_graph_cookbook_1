#include "create_tutorial_chapters_graph.h"

#include "save_named_vertices_graph_to_dot.h"

#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>
#include <sstream>

#include "copy_file.h"
#include "convert_dot_to_svg.h"
#include "is_valid_dot_file.h"
#include "create_named_vertices_k2_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"
#include "create_empty_directed_named_vertices_graph.h"
#include "add_named_vertex.h"
#include "add_edge_between_named_vertices.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::directedS,
  boost::property<boost::vertex_name_t,std::string>
>
create_tutorial_subchapters_graph() noexcept
{
  auto g = create_empty_directed_named_vertices_graph();
  add_named_vertex("Creating an empty directed graph", g);
  add_named_vertex("Creating an empty undirected graph", g);
  add_named_vertex("Add a vertex with a property", g);
  add_named_vertex("Getting the vertices' properties", g);
  add_named_vertex("Creating a non-empty directed graph", g);
  add_named_vertex("Creating a non-empty undirected graph", g);
  add_named_vertex("Has a vertex with a certain property", g);
  add_named_vertex("Find a vertex by its property", g);
  add_named_vertex("Get a vertex its property", g);
  add_named_vertex("Set a vertex its property", g);
  add_named_vertex("Set all vertices' properties", g);
  add_named_vertex("Save the graph with those properties", g);
  add_named_vertex("Load a directed graph with those properties from file", g);
  add_named_vertex("Load an undirected graph with those properties from file", g);

  {
    const std::string s = "Creating an empty directed graph";
    add_edge_between_named_vertices(s, "Creating an empty undirected graph", g);
    add_edge_between_named_vertices(s, "Add a vertex with a property", g);
  }
  {
    const std::string s = "Creating an empty undirected graph";
    add_edge_between_named_vertices(s, "Add a vertex with a property", g);
  }
  {
    const std::string s = "Add a vertex with a property";
    add_edge_between_named_vertices(s, "Getting the vertices' properties", g);
    add_edge_between_named_vertices(s, "Creating a non-empty directed graph", g);
    add_edge_between_named_vertices(s, "Creating a non-empty undirected graph", g);
  }
  {
    const std::string s = "Getting the vertices' properties";
    add_edge_between_named_vertices(s, "Creating a non-empty directed graph", g);
    add_edge_between_named_vertices(s, "Creating a non-empty undirected graph", g);
  }
  {
    const std::string s = "Creating a non-empty directed graph";
    add_edge_between_named_vertices(s, "Has a vertex with a certain property", g);
    add_edge_between_named_vertices(s, "Find a vertex by its property", g);
    add_edge_between_named_vertices(s, "Save the graph with those properties", g);
  }
  {
    const std::string s = "Creating a non-empty undirected graph";
    add_edge_between_named_vertices(s, "Has a vertex with a certain property", g);
    add_edge_between_named_vertices(s, "Find a vertex by its property", g);
    add_edge_between_named_vertices(s, "Save the graph with those properties", g);
  }
  {
    const std::string s = "Has a vertex with a certain property";
    add_edge_between_named_vertices(s, "Find a vertex by its property", g);
  }
  {
    const std::string s = "Find a vertex by its property";
    add_edge_between_named_vertices(s, "Get a vertex its property", g);
  }
  {
    const std::string s = "Get a vertex its property";
    add_edge_between_named_vertices(s, "Set a vertex its property", g);
  }
  {
    const std::string s = "Set a vertex its property";
    add_edge_between_named_vertices(s, "Set all vertices' properties", g);
  }
  {
    const std::string s = "Set all vertices' properties";
    add_edge_between_named_vertices(s, "Save the graph with those properties", g);
  }
  {
    const std::string s = "Save the graph with those properties";
    add_edge_between_named_vertices(s, "Load a directed graph with those properties from file", g);
    add_edge_between_named_vertices(s, "Load an undirected graph with those properties from file", g);
  }
  {
    const std::string s = "Load a directed graph with those properties from file";
  }
  {
    const std::string s = "Load an undirected graph with those properties from file";
  }

  return g;
}



BOOST_AUTO_TEST_CASE(create_tutorial_subchapters_graph_thorough)
{
  {
    const auto g = create_tutorial_subchapters_graph();
    const std::string base_filename{"create_tutorial_subchapters_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_named_vertices_graph_to_dot(g,dot_filename);
    BOOST_CHECK(is_valid_dot_file(dot_filename));
    convert_dot_to_svg(dot_filename,svg_filename);
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
