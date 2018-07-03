#include "convert_svg_to_png.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_convert_svg_to_png)
{
  BOOST_CHECK_THROW(convert_svg_to_png("dont_exists.svg", "dont_exists.png"),
    std::invalid_argument);
}
