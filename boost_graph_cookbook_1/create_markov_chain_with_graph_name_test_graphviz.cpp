#include "create_markov_chain_with_graph_name.h"

#include <boost/test/unit_test.hpp>

#include "is_valid_dot_file.h"
#include "is_regular_file.h"
#include "copy_file.h"
#include "convert_dot_to_svg.h"
#include "save_graph_with_graph_name_to_dot.h"
#include "load_directed_graph_with_graph_name_from_dot.h"

BOOST_AUTO_TEST_CASE(create_markov_chain_with_graph_name_save_and_load_should_be_equal)
{
  const auto g = create_markov_chain_with_graph_name();
  const std::string base_filename{"create_markov_chain_with_graph_name_save_and_load_should_be_equal"};
  const std::string dot_filename{base_filename + ".dot"};
  save_graph_with_graph_name_to_dot(g, dot_filename);
  BOOST_CHECK(is_valid_dot_file(dot_filename));
  const auto h = load_directed_graph_with_graph_name_from_dot(dot_filename);
  BOOST_CHECK(get_graph_name(g) == get_graph_name(h));
  std::remove(dot_filename.c_str());
}

BOOST_AUTO_TEST_CASE(create_markov_chain_with_graph_name_create_pictures)
{
  return; //Issue #39
  try
  {
    BOOST_TEST_PASSPOINT();
    const auto g = create_markov_chain_with_graph_name();
    BOOST_TEST_PASSPOINT();
    const std::string base_filename{"create_markov_chain_with_graph_name"};
    const std::string dot_filename{base_filename + ".dot"};
    //Clean up
    BOOST_TEST_PASSPOINT();
    if (is_regular_file(dot_filename))
    {
      BOOST_TEST_PASSPOINT();
      std::remove(dot_filename.c_str());
    }
    BOOST_TEST_PASSPOINT();
    BOOST_CHECK(!is_regular_file(dot_filename));
    save_graph_with_graph_name_to_dot(g, dot_filename);
    BOOST_TEST_PASSPOINT();
    BOOST_CHECK(is_regular_file(dot_filename));
    BOOST_CHECK(is_valid_dot_file(dot_filename));
    copy_file(
      dot_filename,
      "../boost_graph_cookbook_1/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    BOOST_TEST_PASSPOINT();
    const std::string svg_filename{base_filename + ".svg"};
    convert_dot_to_svg(dot_filename, svg_filename); //ERROR
    BOOST_TEST_PASSPOINT();
    copy_file(
      svg_filename,
      "../boost_graph_cookbook_1/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
    BOOST_TEST_PASSPOINT();
    std::remove(dot_filename.c_str());
    BOOST_TEST_PASSPOINT();
    std::remove(svg_filename.c_str());
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
