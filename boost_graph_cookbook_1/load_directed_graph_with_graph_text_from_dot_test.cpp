#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
#include "load_directed_graph_with_graph_text_from_dot.h"
#include "load_directed_graph_with_graph_text_from_dot_demo.impl"


#include <boost/test/unit_test.hpp>
#include "get_graph_text.h"
#include "copy_file.h"
#include "save_graph_with_graph_text_to_dot.h"
#include "save_graph_with_graph_text_to_dot.h"
#include "create_markov_chain_with_graph_text.h"
#include "convert_dot_to_svg.h"
#include "is_regular_file.h"
#include "file_to_vector.h"
#include "set_graph_text.h"

BOOST_AUTO_TEST_CASE(load_directed_graph_with_graph_text_from_dot_thorough)
{
  //Create the picture 'load_directed_graph_with_graph_text_from_dot_test_markov_chain.svg'
  {
    auto g = create_empty_directed_graph_with_graph_text();
    //const auto g = create_markov_chain_with_graph_text();
    const std::string base_filetext{"create_empty_directed_graph_with_graph_text"};
    const std::string dot_filetext{base_filetext + ".dot"};
    const std::string svg_filetext{base_filetext + ".svg"};
    set_graph_text("TestGraph", g);
    BOOST_CHECK(get_graph_text(g) == "TestGraph");
    save_graph_with_graph_text_to_dot(g, dot_filetext);
    const auto h = load_directed_graph_with_graph_text_from_dot(dot_filetext);
    BOOST_CHECK(get_graph_text(g) == get_graph_text(h));
    convert_dot_to_svg(dot_filetext, svg_filetext);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    copy_file(
      dot_filetext,
      "../boost_graph_cookbook_1/" + dot_filetext,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      svg_filetext,
      "../boost_graph_cookbook_1/" + svg_filetext,
      copy_file_mode::allow_overwrite
    );
  }
  
}

BOOST_AUTO_TEST_CASE(load_directed_graph_with_graph_text_from_dot_when_file_is_absent)
{
  const std::string dot_filetext{
    "load_directed_graph_with_graph_text_from_dot_when_file_is_absent.dot"
  };
  assert(!is_regular_file(dot_filetext));
  BOOST_CHECK_THROW(
    load_directed_graph_with_graph_text_from_dot(dot_filetext),
    std::invalid_argument
  );
}

#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
