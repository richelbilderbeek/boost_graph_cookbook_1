#include "file_to_vector.h"

#include <fstream>
#include <boost/test/unit_test.hpp>
#include "is_regular_file.h"

BOOST_AUTO_TEST_CASE(test_file_to_vector_open_nonexisting_file)
{
  BOOST_CHECK_THROW(
    file_to_vector("dont_exists.txt"),
    std::invalid_argument
  );
}
