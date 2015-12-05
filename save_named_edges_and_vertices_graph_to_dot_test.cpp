#include "save_named_edges_and_vertices_graph_to_dot_test.h"

#include <cassert>
#include <iostream>
#include <sstream>

#include "fileio.h"
#include "create_named_vertices_k2_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"
#include "create_router_network_graph.h"
#include "show_dot.h"

void save_named_edges_and_vertices_graph_to_dot_test() noexcept
{
  //Should not compile on graphs without named vertices. It does not :-)
  {
    const auto g = create_named_vertices_k2_graph();
    const std::string filename{"save_named_edges_and_vertices_graph_to_dot_test_named_vertices_k2_graph.dot"};
    save_named_edges_and_vertices_graph_to_dot(g,filename);
  }
  //Show it does not store the edges' names
  {
    const auto g = create_named_edges_and_vertices_k3_graph();
    const std::string filename{"save_named_edges_and_vertices_graph_to_dot_test_named_edges_and_vertices_k3_graph.dot"};
    save_named_edges_and_vertices_graph_to_dot(g,filename);
    const std::vector<std::string> text{
      ribi::FileIo().FileToVector(filename)
    };
    assert(!text.empty());
    const std::vector<std::string> expected_text{
      "graph G {",
      "0[label=top];",
      "1[label=right];",
      "2[label=left];",
      "0--1 ;",
      "1--2 ;",
      "2--0 ;",
      "}"
    };
    assert(text != expected_text);
    //show_dot(filename);
    std::stringstream cmd;
    cmd << "cp " << filename << " ../BoostGraphTutorial";
    std::system(cmd.str().c_str());
  }
  std::cout << __func__ << ": OK" << '\n';
}
