#include "file_to_vector.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_file_to_vector)
{
  BOOST_CHECK_THROW(
    file_to_vector("dont_exists.txt"),
    std::invalid_argument
  );
}
