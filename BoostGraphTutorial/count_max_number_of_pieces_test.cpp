#include "count_max_number_of_pieces.h"
#include <boost/test/unit_test.hpp>
#include "create_path_graph.h"
#include "create_petersen_graph.h"

BOOST_AUTO_TEST_CASE(test_count_max_number_of_pieces)
{
  {
    const auto g = create_path_graph(0);
    BOOST_CHECK_EQUAL(count_max_number_of_pieces(g), 0);
  }
  {
    const auto g = create_path_graph(1);
    BOOST_CHECK_EQUAL(count_max_number_of_pieces(g), 1);
  }
  {
    const auto g = create_path_graph(2);
    BOOST_CHECK_EQUAL(count_max_number_of_pieces(g), 1);
  }
  {
    const auto g = create_path_graph(3);
    BOOST_CHECK_EQUAL(count_max_number_of_pieces(g), 2);
  }
  {
    const auto g = create_path_graph(4);
    BOOST_CHECK_EQUAL(count_max_number_of_pieces(g), 2);
  }
  {
    const auto g = create_path_graph(5);
    BOOST_CHECK_EQUAL(count_max_number_of_pieces(g), 3);
  }
  {
    const auto g = create_petersen_graph();
    BOOST_CHECK_EQUAL(count_max_number_of_pieces(g), 4); //SHOULD FAIL
  }
}

