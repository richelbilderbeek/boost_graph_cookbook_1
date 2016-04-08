#include "convert_dot_to_svg.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_convert_dot_to_svg)
{
  BOOST_CHECK_THROW(
    convert_dot_to_svg("dont_exists.dot", "dont_exists.svg"),
    std::invalid_argument
  );
}
