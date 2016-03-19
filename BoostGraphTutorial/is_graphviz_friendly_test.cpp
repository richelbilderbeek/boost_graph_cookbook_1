#include "is_graphviz_friendly.h"

#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_CASE(is_graphviz_friendly_thorough)
{
  BOOST_CHECK( is_graphviz_friendly("abcdef"));
  BOOST_CHECK(!is_graphviz_friendly("ab< \" \\ cd$ef"));
}
