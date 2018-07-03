#include "get_bits.h"
#include <algorithm>
#include <cassert>
#include <sstream>
#include <stdexcept>

std::vector<int> get_bits(int value)
{
  if (value < 0) {
    std::stringstream msg;
    msg << __func__ << ": "
        << "need positive value, instead of " << value;
    throw std::invalid_argument(msg.str());
  }

  std::vector<int> v;
  int index = 0;
  while (value > 0) {
    if (value % 2 != 0) // value % 2 == 1 does not work for negative numbers
    {
      v.push_back(index);
    }
    value /= 2;
    ++index;
  }
  assert(std::is_sorted(std::begin(v), std::end(v)));
  return v;
}
