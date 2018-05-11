#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
#include "load_directed_graph_with_graph_name_from_dot.h"
#include "load_directed_graph_with_graph_name_from_dot_demo.impl"


#include <boost/test/unit_test.hpp>
#include "get_graph_name.h"
#include "copy_file.h"
#include "save_graph_with_graph_name_to_dot.h"
#include "save_graph_with_graph_name_to_dot.h"
#include "create_markov_chain_with_graph_name.h"
#include "convert_dot_to_svg.h"
#include "is_regular_file.h"
#include "file_to_vector.h"
#include "set_graph_name.h"

BOOST_AUTO_TEST_CASE(load_directed_graph_with_graph_name_from_dot_thorough)
{
  //Create the picture 'load_directed_graph_with_graph_name_from_dot_test_markov_chain.svg'
  {
    auto g = create_empty_directed_graph_with_graph_name();
    //const auto g = create_markov_chain_with_graph_name();
    const std::string base_filename{"create_empty_directed_graph_with_graph_name"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    set_graph_name("TestGraph", g);
    BOOST_CHECK(get_graph_name(g) == "TestGraph");
    save_graph_with_graph_name_to_dot(g, dot_filename);
    const auto h = load_directed_graph_with_graph_name_from_dot(dot_filename);
    BOOST_CHECK(get_graph_name(g) == get_graph_name(h));
    convert_dot_to_svg(dot_filename, svg_filename);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    copy_file(
      dot_filename,
      "../boost_graph_cookbook_1/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      svg_filename,
      "../boost_graph_cookbook_1/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
  }
  
}

BOOST_AUTO_TEST_CASE(load_directed_graph_with_graph_name_from_dot_when_file_is_absent)
{
  const std::string dot_filename{
    "load_directed_graph_with_graph_name_from_dot_when_file_is_absent.dot"
  };
  assert(!is_regular_file(dot_filename));
  BOOST_CHECK_THROW(
    load_directed_graph_with_graph_name_from_dot(dot_filename),
    std::invalid_argument
  );
}

#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
