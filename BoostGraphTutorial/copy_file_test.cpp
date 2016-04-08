#include "copy_file.h"
#include <fstream>
#include <boost/test/unit_test.hpp>
#include "is_regular_file.h"

BOOST_AUTO_TEST_CASE(test_copy_file)
{
  BOOST_CHECK_THROW(
    copy_file("dont_exists.nxi", "dont_exists.png", copy_file_mode::prevent_overwrite),
    std::invalid_argument
  );
  const std::string filename_a{"temp_test_copy_file_a.txt"};
  const std::string filename_b{"temp_test_copy_file_b.txt"};
  { std::ofstream f(filename_a); f << "filename_a"; }
  { std::ofstream f(filename_b); f << "filename_b"; }
  assert(is_regular_file(filename_a));
  assert(is_regular_file(filename_b));

  //BOOST_CHECK_NO_THROW(
    copy_file(filename_a, filename_b, copy_file_mode::allow_overwrite)
  //)
  ;
  BOOST_CHECK_THROW(
    copy_file(filename_a, filename_b, copy_file_mode::prevent_overwrite),
    std::invalid_argument
  );
  std::remove(filename_a.c_str());
  std::remove(filename_b.c_str());
}
