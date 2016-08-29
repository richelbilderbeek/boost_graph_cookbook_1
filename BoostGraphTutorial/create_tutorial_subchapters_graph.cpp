#include "create_tutorial_chapters_graph.h"

#include "save_named_vertices_graph_to_dot.h"




#include <sstream>

#include "copy_file.h"
#include "convert_dot_to_svg.h"
#include "is_valid_dot_file.h"
#include "create_named_vertices_k2_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"
#include "create_empty_directed_named_vertices_graph.h"
#include "add_named_vertex.h"
#include "add_edge_between_named_vertices.h"

boost::adjacency_list< //!OCLINT Sure it is too long, but this is just a fun function
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
    add_edge_between_named_vertices(s, std::string("Creating an empty undirected graph"), g);
    add_edge_between_named_vertices(s, std::string("Add a vertex with a property"), g);
  }
  {
    const std::string s = "Creating an empty undirected graph";
    add_edge_between_named_vertices(s, std::string("Add a vertex with a property"), g);
  }
  {
    const std::string s = "Add a vertex with a property";
    add_edge_between_named_vertices(s, std::string("Getting the vertices' properties"), g);
    add_edge_between_named_vertices(s, std::string("Creating a non-empty directed graph"), g);
    add_edge_between_named_vertices(s, std::string("Creating a non-empty undirected graph"), g);
  }
  {
    const std::string s = "Getting the vertices' properties";
    add_edge_between_named_vertices(s, std::string("Creating a non-empty directed graph"), g);
    add_edge_between_named_vertices(s, std::string("Creating a non-empty undirected graph"), g);
  }
  {
    const std::string s = "Creating a non-empty directed graph";
    add_edge_between_named_vertices(s, std::string("Has a vertex with a certain property"), g);
    add_edge_between_named_vertices(s, std::string("Find a vertex by its property"), g);
    add_edge_between_named_vertices(s, std::string("Save the graph with those properties"), g);
  }
  {
    const std::string s = "Creating a non-empty undirected graph";
    add_edge_between_named_vertices(s, std::string("Has a vertex with a certain property"), g);
    add_edge_between_named_vertices(s, std::string("Find a vertex by its property"), g);
    add_edge_between_named_vertices(s, std::string("Save the graph with those properties"), g);
  }
  {
    const std::string s = "Has a vertex with a certain property";
    add_edge_between_named_vertices(s, std::string("Find a vertex by its property"), g);
  }
  {
    const std::string s = "Find a vertex by its property";
    add_edge_between_named_vertices(s, std::string("Get a vertex its property"), g);
  }
  {
    const std::string s = "Get a vertex its property";
    add_edge_between_named_vertices(s, std::string("Set a vertex its property"), g);
  }
  {
    const std::string s = "Set a vertex its property";
    add_edge_between_named_vertices(s, std::string("Set all vertices' properties"), g);
  }
  {
    const std::string s = "Set all vertices' properties";
    add_edge_between_named_vertices(s, std::string("Save the graph with those properties"), g);
  }
  {
    const std::string s = "Save the graph with those properties";
    add_edge_between_named_vertices(
      s, std::string("Load a directed graph with those properties from file"), g
    );
    add_edge_between_named_vertices(
      s, std::string("Load an undirected graph with those properties from file"), g
    );
  }
  return g;
}



