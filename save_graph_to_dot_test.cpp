#include "save_graph_to_dot.h"

#include <iostream>
#include <sstream>

#include "fileio.h"
#include "create_k2_graph.h"
#include "create_named_vertices_k2_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"
#include "create_router_network_graph.h"
#include "show_dot.h"

void save_graph_to_dot_test() noexcept
{
  {
    const auto g = create_k2_graph();
    const std::string filename{"save_graph_to_dot_test_k2_graph.dot"};
    save_graph_to_dot(g,filename);
    const std::vector<std::string> text{
      ribi::FileIo().FileToVector(filename)
    };
    const std::vector<std::string> expected_text{
      "graph G {",
      "0;",
      "1;",
      "0--1 ;",
      "}"
    };
    assert(text == expected_text);
    //show_dot(filename);
    std::stringstream cmd;
    cmd << "cp " << filename << " ../BoostGraphTutorial";
    std::system(cmd.str().c_str());
  }
  //Show it does not store the vertex names
  {
    const auto g = create_named_vertices_k2_graph();
    const std::string filename{"save_graph_to_dot_test_named_vertices_k2_graph.dot"};
    save_graph_to_dot(g,filename);
    const std::vector<std::string> text{
      ribi::FileIo().FileToVector(filename)
    };
    const std::vector<std::string> expected_text{
      "graph G {",
      "0;",
      "1;",
      "0--1 ;",
      "}"
    };
    assert(text == expected_text);
    //show_dot(filename);
    std::stringstream cmd;
    cmd << "cp " << filename << " ../BoostGraphTutorial";
    std::system(cmd.str().c_str());
  }
  std::cout << __func__ << ": OK" << '\n';
}
