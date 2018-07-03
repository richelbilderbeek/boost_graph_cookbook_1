#include "get_bits.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_get_bits)
{
  {
    const auto result = get_bits(0);
    const std::vector<int> expected = {};
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(result), std::end(result),
      std::begin(expected), std::end(expected));
  }
  {
    const auto result = get_bits(1);
    const std::vector<int> expected = { 0 };
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(result), std::end(result),
      std::begin(expected), std::end(expected));
  }
  {
    const auto result = get_bits(2);
    const std::vector<int> expected = { 1 };
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(result), std::end(result),
      std::begin(expected), std::end(expected));
  }
  {
    const auto result = get_bits(3);
    const std::vector<int> expected = { 0, 1 };
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(result), std::end(result),
      std::begin(expected), std::end(expected));
  }
  {
    const auto result = get_bits(4);
    const std::vector<int> expected = { 2 };
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(result), std::end(result),
      std::begin(expected), std::end(expected));
  }
  {
    const auto result = get_bits(5);
    const std::vector<int> expected = { 0, 2 };
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(result), std::end(result),
      std::begin(expected), std::end(expected));
  }
  {
    const auto result = get_bits(6);
    const std::vector<int> expected = { 1, 2 };
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(result), std::end(result),
      std::begin(expected), std::end(expected));
  }
  {
    const auto result = get_bits(7);
    const std::vector<int> expected = { 0, 1, 2 };
    BOOST_CHECK_EQUAL_COLLECTIONS(std::begin(result), std::end(result),
      std::begin(expected), std::end(expected));
  }
}

BOOST_AUTO_TEST_CASE(test_get_bits_for_negative_value)
{
  BOOST_CHECK_THROW(get_bits(-42), std::invalid_argument);
}
