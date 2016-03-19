#include "create_markov_chain_with_graph_name.h"
#include "create_markov_chain_with_graph_name_demo.impl"

#include <boost/test/unit_test.hpp>

#include "copy_file.h"
#include "convert_dot_to_svg.h"
#include "save_graph_with_graph_name_to_dot.h"
#include "load_directed_graph_with_graph_name_from_dot.h"

BOOST_AUTO_TEST_CASE(create_markov_chain_with_graph_name_thorough)
{
  //Basic tests
  {
    const auto g = create_markov_chain_with_graph_name();
    BOOST_CHECK(boost::num_vertices(g) == 2);
    BOOST_CHECK(boost::num_edges(g) == 4);
    BOOST_CHECK(get_graph_name(g) == "Two-state Markov chain");

  }
  //Check if saving and loading results in the graph with the same name
  {
    const auto g = create_markov_chain_with_graph_name();
    const std::string base_filename{"create_markov_chain_with_graph_name"};
    const std::string dot_filename{base_filename + ".dot"};
    save_graph_with_graph_name_to_dot(g, dot_filename);
    const auto h = load_directed_graph_with_graph_name_from_dot(dot_filename);
    BOOST_CHECK(get_graph_name(g) == get_graph_name(h));
  }
  //Create the .dot and .svg of the 'create_markov_chain' chapter
  {
    const auto g = create_markov_chain_with_graph_name();
    const std::string base_filename{"create_markov_chain_with_graph_name"};
    const std::string dot_filename{base_filename + ".dot"};
    save_graph_with_graph_name_to_dot(g, dot_filename);
    copy_file(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    const std::string svg_filename{base_filename + ".svg"};
    convert_dot_to_svg(dot_filename, svg_filename);
    copy_file(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
  }
}
