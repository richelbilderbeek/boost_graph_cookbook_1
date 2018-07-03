#include "create_markov_chain_with_graph_text.h"

#include <boost/test/unit_test.hpp>

#include "is_valid_dot_file.h"
#include "is_regular_file.h"
#include "copy_file.h"
#include "convert_dot_to_svg.h"
#include "save_graph_with_graph_text_to_dot.h"
#include "load_directed_graph_with_graph_text_from_dot.h"

BOOST_AUTO_TEST_CASE(create_markov_chain_with_graph_text_save_and_load_should_be_equal)
{
  const auto g = create_markov_chain_with_graph_text();
  const std::string base_filetext{"create_markov_chain_with_graph_text_save_and_load_should_be_equal"};
  const std::string dot_filetext{base_filetext + ".dot"};
  save_graph_with_graph_text_to_dot(g, dot_filetext);
  BOOST_CHECK(is_valid_dot_file(dot_filetext));
  const auto h = load_directed_graph_with_graph_text_from_dot(dot_filetext);
  BOOST_CHECK(get_graph_text(g) == get_graph_text(h));
  std::remove(dot_filetext.c_str());
}

BOOST_AUTO_TEST_CASE(create_markov_chain_with_graph_text_create_pictures)
{
  return; //Issue #39
  try
  {
    BOOST_TEST_PASSPOINT();
    const auto g = create_markov_chain_with_graph_text();
    BOOST_TEST_PASSPOINT();
    const std::string base_filetext{"create_markov_chain_with_graph_text"};
    const std::string dot_filetext{base_filetext + ".dot"};
    //Clean up
    BOOST_TEST_PASSPOINT();
    if (is_regular_file(dot_filetext))
    {
      BOOST_TEST_PASSPOINT();
      std::remove(dot_filetext.c_str());
    }
    BOOST_TEST_PASSPOINT();
    BOOST_CHECK(!is_regular_file(dot_filetext));
    save_graph_with_graph_text_to_dot(g, dot_filetext);
    BOOST_TEST_PASSPOINT();
    BOOST_CHECK(is_regular_file(dot_filetext));
    BOOST_CHECK(is_valid_dot_file(dot_filetext));
    copy_file(
      dot_filetext,
      "../boost_graph_cookbook_1/" + dot_filetext,
      copy_file_mode::allow_overwrite
    );
    BOOST_TEST_PASSPOINT();
    const std::string svg_filetext{base_filetext + ".svg"};
    convert_dot_to_svg(dot_filetext, svg_filetext); //ERROR
    BOOST_TEST_PASSPOINT();
    copy_file(
      svg_filetext,
      "../boost_graph_cookbook_1/" + svg_filetext,
      copy_file_mode::allow_overwrite
    );
    BOOST_TEST_PASSPOINT();
    std::remove(dot_filetext.c_str());
    BOOST_TEST_PASSPOINT();
    std::remove(svg_filetext.c_str());
    BOOST_TEST_PASSPOINT();
  }
  catch (std::exception& e)
  {
    BOOST_TEST_PASSPOINT();
    std::cerr << e.what() << '\n';
    BOOST_CHECK(!"Should not get here");
  }
  BOOST_TEST_PASSPOINT();
}
